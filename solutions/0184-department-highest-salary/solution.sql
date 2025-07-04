# Write your MySQL query statement below

-- Find the highest salary of each department,
-- then find the names who earn that much salary based on department

-- SELECT d.name, e.name, e.salary FROM Employee
-- JOIN department ON d.name = e.departmentId

-- SELECT departmentId, MAX(salary) FROM Employee
-- GROUP BY salary;

SELECT d.name as Department, e1.name as Employee, e1.salary as Salary FROM Employee e1
JOIN Department d ON e1.departmentId = d.id 
WHERE e1.salary >= ALL(SELECT salary FROM Employee e2 WHERE e1.departmentId = e2.departmentId);
