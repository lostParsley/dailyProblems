# Write your MySQL query statement below
select p.product_name , sum(o.unit) as unit
from Products p 
join Orders o on p.product_id = o.product_id 
where month(o.order_date) = 2 and year(o.order_date) = 2020
GROUP BY p.product_id, p.product_name
HAVING SUM(o.unit) >= 100;