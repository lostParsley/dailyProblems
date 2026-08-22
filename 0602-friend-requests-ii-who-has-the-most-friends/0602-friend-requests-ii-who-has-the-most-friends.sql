# Write your MySQL query statement below
select id , num 
from
(select id , count(id) as num
from 
(select requester_id as id from RequestAccepted 
union  all
select accepter_id from RequestAccepted ) as p 
group by p.id ) as q
order by num desc
limit 1