# Write your MySQL query statement below
SELECT e1.employee_id, e1.name, count(e2.reports_to) AS reports_count, ROUND(AVG(e2.age*1.00),0) AS average_age FROM Employees AS e1 
INNER JOIN Employees AS e2
ON e1.employee_id = e2.reports_to
group by e1.employee_id,e1.name
ORDER BY e1.employee_id