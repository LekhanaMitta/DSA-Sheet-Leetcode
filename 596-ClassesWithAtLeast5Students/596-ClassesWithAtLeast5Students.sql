-- Last updated: 2/9/2026, 1:27:56 PM
# Write your MySQL query statement below
SELECT class FROM Courses
GROUP BY class HAVING COUNT(*) >= 5;