-- Last updated: 2/9/2026, 1:26:58 PM
# Write your MySQL query statement below
SELECT eu.unique_id, e.name FROM Employees e
LEFT JOIN EmployeeUNI eu ON eu.id = e.id;
