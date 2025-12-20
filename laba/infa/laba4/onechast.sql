CREATE database sales_db;

\c sales_db;

CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    price DECIMAL(10, 2) NOT NULL
);

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    order_date DATE NOT NULL DEFAULT CURRENT_DATE
);

CREATE TABLE order_items (
    order_item_id SERIAL PRIMARY KEY,
    order_id INT NOT NULL,
    product_id INT NOT NULL,
    quantity INT NOT NULL,
    total_price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (order_id) REFERENCES orders(order_id) ON DELETE CASCADE,
    FOREIGN KEY (product_id) REFERENCES products(id) ON DELETE CASCADE
);

CREATE INDEX idx_order_date ON orders(order_date);
CREATE INDEX idx_product_id ON order_items(product_id);

INSERT INTO products (name, price) VALUES 
('Laptop', 999.99),
('Mouse', 25.50),
('Keyboard', 75.00),
('Monitor', 299.99),
('Headphones', 150.00);

INSERT INTO orders (order_date) VALUES 
('2024-01-15'),
('2024-01-16'),
('2024-01-17');

INSERT INTO order_items (order_id, product_id, quantity, total_price) VALUES 
(1, 1, 1, 999.99),
(1, 2, 2, 51.00),
(2, 3, 1, 75.00),
(2, 4, 1, 299.99),
(3, 5, 3, 450.00),
(3, 2, 1, 25.50);

SELECT * FROM products;
SELECT * FROM orders;
SELECT * FROM order_items;