# Write your MySQL query statement below
select t.name as results
from 
(select u.name , count(m.movie_id) as tot
from Users u 
join MovieRating m on u.user_id = m.user_id

group by u.user_id 
order by tot desc ,  name
limit 1) as t

union all

select p.title as results
from (
select avg(m.rating) as avg , u.title
from Movies u 
join MovieRating m on u.movie_id = m.movie_id
where month(m.created_at) = 2 and year(m.created_at) = 2020
group by u.title
order by avg desc, u.title
limit 1) as p 