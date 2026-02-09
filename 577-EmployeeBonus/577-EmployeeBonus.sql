-- Last updated: 2/9/2026, 1:28:00 PM
# Write your MySQL query statement below
SELECT name, bonus FROM Employee as e
LEFT JOIN Bonus as b ON e.empId = b.empId
WHERE bonus < 1000 OR bonus IS NULL;