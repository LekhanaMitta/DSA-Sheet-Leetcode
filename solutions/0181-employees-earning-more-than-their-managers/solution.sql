# Write your MySQL query statement below
-- SELECT name as Employee FROM Employee e1
-- WHERE e1.salary > (SELECT salary FROM Employee e2 
-- WHERE e1.managerID = e2.id);

SELECT e1.name as Employee FROM Employee e1, Employee e2
WHERE e1.managerId = e2.Id AND e1.salary > e2.salary;
