select person_name
from
(
    SELECT 
        person_name,
        SUM(weight) over (order by Turn) AS total_weight
    FROM Queue) as q
where total_weight <= 1000
order by total_weight desc  
limit 1 