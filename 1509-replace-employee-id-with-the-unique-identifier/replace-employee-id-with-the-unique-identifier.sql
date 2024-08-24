# Write your MySQL query statement below
SELECT unique_id, name FROM Employees as E
LEFT JOIN EmployeeUNI as EUNI
ON E.id = EUNI.id