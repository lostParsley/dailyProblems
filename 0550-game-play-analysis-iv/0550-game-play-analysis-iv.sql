select
    ROUND(
        COUNT(DISTINCT a.player_id) /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
from Activity a
join 
    (SELECT
            player_id,
            MIN(event_date) AS first_date
        FROM Activity
        GROUP BY player_id) as t
on a.player_id = t.player_id and a.event_date = date_add(t.first_date , interval 1 day)
    