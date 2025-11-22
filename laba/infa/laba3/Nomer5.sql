SELECT id, name, price 
FROM products 
ORDER BY price DESC;

SELECT 
    oi.order_item_id,
    p.name AS product_name,
    oi.quantity,
    oi.total_price
FROM order_items oi
JOIN products p ON oi.product_id = p.id
WHERE oi.order_id = 2;

SELECT 
    o.order_id,
    o.order_date,
    SUM(oi.total_price) AS total_order_amount
FROM orders o
JOIN order_items oi ON o.order_id = oi.order_id
WHERE o.order_id = 2
GROUP BY o.order_id, o.order_date;

SELECT 
    o.order_id,
    o.order_date,
    SUM(oi.total_price) AS total_amount
FROM orders o
JOIN order_items oi ON o.order_id = oi.order_id
WHERE o.order_date BETWEEN '2024-01-15' AND '2024-01-17'
GROUP BY o.order_id, o.order_date
ORDER BY o.order_date;