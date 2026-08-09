# Write your MySQL query statement below
select 
    ROUND(
    SUM(
        IF(
            query.date = d.customer_pref_delivery_date,
            1,
            0
        )
    ) * 100 / COUNT(d.customer_id),
    2
) AS immediate_percentage  
           
from Delivery as d 
join 
     (select customer_id , 
                min(order_date) as date 
            from Delivery d 
            group by customer_id ) as query 
on d.customer_id  = query.customer_id and d.order_date = query.date