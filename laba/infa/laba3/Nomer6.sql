SELECT 
    p.name AS product_name,
    SUM(oi.quantity) AS total_quantity_ordered,
    COUNT(oi.order_item_id) AS number_of_orders,
    SUM(oi.total_price) AS total_revenue
FROM products p
JOIN order_items oi ON p.id = oi.product_id
JOIN orders o ON oi.order_id = o.order_id
WHERE o.order_date BETWEEN '2024-01-15' AND '2024-01-18'
GROUP BY p.id, p.name
ORDER BY total_quantity_ordered DESC;

UPDATE products 
SET price = 850.00 
WHERE id = 2;  

DELETE FROM order_items 
WHERE order_item_id = 5;

SELECT * FROM order_items WHERE order_item_id = 5;