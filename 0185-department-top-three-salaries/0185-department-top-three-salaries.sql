
select departmentName as Department , name as Employee , Salary
from 
(SELECT *,
       DENSE_RANK() OVER (
           PARTITION BY p.departmentId
           ORDER BY p.salary DESC
       ) AS rnk
FROM (
    SELECT e.id AS employeeId,
           e.name,
           e.salary,
           e.departmentId,
           d.name AS departmentName
    FROM Employee e
    JOIN Department d
        ON e.departmentId = d.id
) AS p) q 
where rnk <= 3