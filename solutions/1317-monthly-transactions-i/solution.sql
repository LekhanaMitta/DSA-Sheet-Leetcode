# Write your MySQL query statement below
SELECT DATE_FORMAT(trans_date, '%Y-%m') AS month, 
country, 
COUNT(*) AS trans_count, 
SUM(state = 'approved') AS approved_count,
SUM(amount) AS trans_total_amount, 
SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount 
 FROM Transactions
 GROUP BY month, country
--  ORDER BY month ASC
;
-- SELECT COUNT(*) AS approved_count FROM Transactions
-- WHERE state LIKE 'approved';

-- SELECT SUM(amount) FROM transactions
-- GROUP BY country;

-- SELECT SUM(amount) FROM transactions
-- WHERE state LIKE 'approved'
-- GROUP BY country;

-- SELECT MONTH(trans_date) AS month
-- FROM transactions;


