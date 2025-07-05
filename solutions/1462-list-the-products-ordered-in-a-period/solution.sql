# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) AS unit FROM Products p
JOIN Orders o ON o.product_id = p.product_id
WHERE o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY p.product_id HAVING SUM(o.unit) >=100;

-- select the product ids who have no. of units >= 100

-- SELECT product_id FROM Orders
-- WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
-- GROUP BY product_id HAVING SUM(unit) >= 100;
