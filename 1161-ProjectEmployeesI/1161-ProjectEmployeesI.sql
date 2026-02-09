-- Last updated: 2/9/2026, 1:27:13 PM
# Write your MySQL query statement below
SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years FROM Employee
JOIN Project ON project.employee_id = Employee.employee_id
GROUP BY project_id;