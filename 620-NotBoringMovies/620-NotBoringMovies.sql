-- Last updated: 2/9/2026, 1:27:52 PM
# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE id % 2 = 1 AND description NOT LIKE 'Boring'
ORDER BY rating DESC;