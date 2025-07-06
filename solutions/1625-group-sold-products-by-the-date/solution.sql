# Write your MySQL query statement below
-- SELECT DISTINCT product FROM Activities
-- GROUP BY sell_date;

SELECT sell_date, COUNT(DISTINCT product) AS num_sold, GROUP_CONCAT(DISTINCT product ORDER BY product ASC) AS products FROM Activities
GROUP BY sell_date ORDER BY sell_date ASC, num_sold DESC;
