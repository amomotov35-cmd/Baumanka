CREATE database sales_db;

CREATE TABLE products(
	id INT PRIMARY KEY,
	name VARCHAR(50) NOT NULL,
	price FLOAT NOT NULL
);

CREATE TABLE orders (
	order_id  INT PRIMARY KEY,
	order_date DATE NOT NULL
);

CREATE TABLE order_items(
	order_item_id INT PRIMARY KEY,
	order_id INT NOT NULL,
	product_id INT NOT NULL,
	quantity INT NOT NULL,
	quantity FLOAT NOT NULL
);

ALTER TABLE order_items ADD FOREIGN KEY (order_id) REFERENCES  orders(order_id);
ALTER TABLE order_items ADD FOREIGN KEY (product_id) REFERENCES products(id);
