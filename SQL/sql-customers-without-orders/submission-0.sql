-- Write your query below
SELECT name 
FROM customers 
WHERE name NOT IN (
    SELECT c.name
    FROM orders as o
    LEFT JOIN customers as c
    ON o.customer_id = c.id
)

