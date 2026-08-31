select d.name as Department , p.name as Employee , p.salary
from
(SELECT *,
           DENSE_RANK() OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rnk
FROM Employee) as p 

join Department d on d.id = p.departmentId
where rnk = 1
order by p.salary desc 