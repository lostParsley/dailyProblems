# Write your MySQL query statement below
select name 
from Employee e
where e.id in 
(select managerId 
from Employee 
group by managerId 
having count(distinct id) >= 5)