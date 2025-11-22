INSERT INTO products(id, name, price) VALUES
(1, 'Ноутбук ASUS', 450),
(2, 'Смартфон Samsung', 250),
(3, 'Наушники Sony', 50),
(4, 'Мышь беспроводная', 15),
(5, 'Клавиатура механическая', 35);
SELECT * FROM products;

INSERT INTO orders (order_id, order_date) VALUES
(1, '2024-01-15'),
(2, '2024-01-16'),
(3, '2024-01-17'),
(4, '2024-01-18'),
(5, '2024-01-19');
SELECT * FROM orders;


INSERT INTO order_items (order_item_id, order_id, product_id, quantity, total_price) VALUES
(1, 1, 1, 1, 450),  
(2, 1, 3, 1, 50),   
(3, 2, 2, 2, 500),  
(4, 2, 4, 1, 15),   
(5, 3, 5, 1, 35),   
(6, 3, 4, 2, 30),   
(7, 4, 3, 3, 150),  
(8, 5, 1, 1, 450),  
(9, 5, 2, 1, 250);
SELECT * FROM order_items;