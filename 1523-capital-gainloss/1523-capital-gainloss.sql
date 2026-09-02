# Write your MySQL query statement below
select distinct stock_name , 
    (
        sum(case when operation = 'Sell' then price else 0 end) over (
            partition by stock_name 
        ) - 
        sum(case when operation = 'Buy' then price else 0 end) over (
            partition by stock_name 
        ) 
    ) as capital_gain_loss  
from Stocks 
