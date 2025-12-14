CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(10) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INTEGER NOT NULL REFERENCES students(student_id) ON DELETE CASCADE,
    subject_id INTEGER NOT NULL REFERENCES subjects(subject_id) ON DELETE CASCADE,
    grade INTEGER CHECK (grade BETWEEN 2 AND 5),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INTEGER NOT NULL REFERENCES students(student_id) ON DELETE CASCADE,
    date_attended DATE NOT NULL,
    status VARCHAR(20) CHECK (status IN ('присутствовал', 'отсутствовал', 'опоздал'))
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INTEGER NOT NULL REFERENCES students(student_id) ON DELETE CASCADE,
    note_text TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO students (full_name, group_number) VALUES
('Слюсаренко Григорий Андреевич', 'ИУ1-11Б'),
('Цуп Алексей Игоривич', 'ИУ1-11Б'),
('Стасенко Максим Михайлович', 'ИУ1-11Б'),
('Волкова Александра Сергеевна', 'ИУ1-11Б'),
('Момотов Артём Сергеевич', 'ИУ1-11Б'),
('Антонов Алексей Евгеньевич', 'ИУ1-11Б');

INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

DO $$
DECLARE
    student RECORD;
    subject RECORD;
    possible_grades INTEGER[] := ARRAY[2,3,4,5];
BEGIN
    FOR student IN SELECT student_id FROM students LOOP
        FOR subject IN SELECT subject_id FROM subjects LOOP
            INSERT INTO grades (student_id, subject_id, grade)
            VALUES (
                student.student_id,
                subject.subject_id,
                possible_grades[1 + floor(random() * array_length(possible_grades, 1))::integer]
            );
        END LOOP;
    END LOOP;
END $$;

INSERT INTO attendance (student_id, date_attended, status)
SELECT 
    student_id,
    '2024-01-15' as date_attended,
    CASE WHEN random() > 0.2 THEN 'присутствовал' ELSE 'отсутствовал' END as status
FROM students;

INSERT INTO attendance (student_id, date_attended, status)
SELECT 
    student_id,
    '2024-01-16' as date_attended,
    CASE WHEN random() > 0.3 THEN 'присутствовал' ELSE 'опоздал' END as status
FROM students;

INSERT INTO notes (student_id, note_text) VALUES
(1, 'Любит информатику, хорошо работает в команде'),
(2, 'Нужна помощь по информатике, прогресс по информатике заметен'),
(3, 'Редко посещает занятия по информатике'),
(4, 'Отличник по всем предметам, особенно силен в математическом анализе'),
(5, 'Хорошо работает в команде, активно участвует на занятиях'),
(6, 'Прогресс по информатике, улучшил оценки по аналитической геометрии');

CREATE INDEX idx_students_group_number ON students(group_number);

CREATE INDEX idx_grades_student_id ON grades(student_id);

CREATE EXTENSION IF NOT EXISTS pg_trgm;
CREATE INDEX idx_notes_note_text_gin ON notes USING gin(note_text gin_trgm_ops);

CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    s.group_number,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name, s.group_number
ORDER BY average_grade DESC NULLS LAST;

BEGIN;

INSERT INTO students (full_name, group_number) 
VALUES ('Марцуль Василий Дмитривич', 'ИУ1-11Б')
RETURNING student_id;

WITH new_student AS (
    SELECT student_id FROM students WHERE full_name = 'Марцуль Василий Дмитривич'
)
INSERT INTO grades (student_id, subject_id, grade)
SELECT 
    (SELECT student_id FROM new_student),
    subject_id,
    CASE subject_name
        WHEN 'Информатика' THEN 5
        WHEN 'Математический анализ' THEN 4
        WHEN 'Аналитическая геометрия' THEN 5
    END as grade
FROM subjects;

COMMIT;

-- Запрос 1
WITH target_student AS (
    SELECT student_id, group_number
    FROM students 
    WHERE full_name = 'Слюсаренко Григорий Андреевич'
),
group_mates AS (
    SELECT 
        s.student_id,
        s.full_name,
        ROW_NUMBER() OVER (ORDER BY s.student_id) as row_num
    FROM students s
    JOIN target_student ts ON s.group_number = ts.group_number
    WHERE s.student_id != ts.student_id
),
target_row AS (
    SELECT row_num
    FROM group_mates 
    WHERE student_id = (SELECT student_id FROM target_student)
)
SELECT 
    gm.full_name,
    gm.student_id
FROM group_mates gm
CROSS JOIN target_row tr
WHERE gm.row_num BETWEEN tr.row_num - 2 AND tr.row_num + 3
AND gm.row_num != tr.row_num
ORDER BY gm.row_num
LIMIT 5;

-- Запрос 2
SELECT * FROM student_avg_grades 
WHERE full_name = 'Слюсаренко Григорий Андреевич';

-- Запрос 3
SELECT 
    s.subject_name,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade,
    COUNT(g.grade_id) as total_grades
FROM subjects s
JOIN grades g ON s.subject_id = g.subject_id
WHERE s.subject_name = 'Информатика'
GROUP BY s.subject_id, s.subject_name;

-- Запрос 4
SELECT 
    s.full_name,
    n.note_text,
    n.created_at
FROM notes n
JOIN students s ON n.student_id = s.student_id
WHERE n.note_text ILIKE '%информатика%'
ORDER BY n.created_at DESC;

-- Запрос 5
BEGIN;

UPDATE attendance
SET status = 'присутствовал'
WHERE student_id = (
    SELECT student_id FROM students WHERE full_name = 'Слюсаренко Григорий Андреевич'
)
AND date_attended = '2024-01-15';

SELECT 
    s.full_name,
    a.date_attended,
    a.status
FROM attendance a
JOIN students s ON a.student_id = s.student_id
WHERE s.full_name = 'Слюсаренко Григорий Андреевич'
AND a.date_attended = '2024-01-15';

COMMIT;


SELECT * FROM student_avg_grades;

SELECT 
    date_attended,
    status,
    COUNT(*) as count
FROM attendance
GROUP BY date_attended, status
ORDER BY date_attended, status;

SELECT 
    s.subject_name,
    ROUND(AVG(g.grade)::numeric, 2) as avg_grade,
    MIN(g.grade) as min_grade,
    MAX(g.grade) as max_grade,
    COUNT(*) as total_grades
FROM subjects s
JOIN grades g ON s.subject_id = g.subject_id
GROUP BY s.subject_id, s.subject_name
ORDER BY avg_grade DESC;