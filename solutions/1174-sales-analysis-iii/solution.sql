# Write your MySQL query statement below
SELECT product_id, product_name FROM Product
WHERE product_id IN (SELECT product_id FROM sales
GROUP BY product_id
HAVING MAX(sale_date) <= '2019-03-31' AND MIN(sale_date) >= '2019-01-01');

