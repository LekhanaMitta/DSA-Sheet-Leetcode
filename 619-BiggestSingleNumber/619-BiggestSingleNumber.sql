-- Last updated: 2/9/2026, 1:27:53 PM
# Write your MySQL query statement below
SELECT (SELECT num FROM MyNumbers
GROUP BY num
HAVING count(*) = 1
ORDER BY num DESC LIMIT 1)  AS num;