-- Last updated: 2/9/2026, 1:27:58 PM
# Write your MySQL query statement below
SELECT customer_number FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC LIMIT 1;