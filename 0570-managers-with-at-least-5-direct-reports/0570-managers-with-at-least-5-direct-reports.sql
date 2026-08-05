# Write your MySQL query statement below
select 
    e1.name
from Employee as e1
left join Employee e2 on e1.id = e2.managerId 
group by e1.id , e2.managerId

having count(*) >= 5