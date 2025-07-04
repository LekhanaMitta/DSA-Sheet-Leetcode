# Write your MySQL query statement below
# First find the first dates of each player 

-- SELECT min(event_date) FROM Activity 
-- GROUP BY player_id ;

-- -- Total players
-- -- SELECT DISTINCT player_id FROM Activity;

-- -- Count the player_id who played the next day of their start date
-- SELECT DISTINCT a.player_id FROM Activity a
-- WHERE a.event_date > (SELECT min(event_date) FROM Activity b
-- WHERE a.player_id = b.player_id);

-- SELECT player_id FROM activity a, activity b
-- WHERE a.player_id = b.player_id 
-- AND a.event_date 

WITH first_date AS (SELECT min(event_date) AS first_login, player_id FROM Activity 
GROUP BY player_id),
next_date AS (SELECT f.player_id FROM first_date f
JOIN Activity a ON a.player_id = f.player_id
AND a.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY)
GROUP BY f.player_id)
SELECT ROUND(1.0*(SELECT COUNT(*) FROM next_date)/(SELECT COUNT(*) FROM first_date), 2) AS FRACTION;
