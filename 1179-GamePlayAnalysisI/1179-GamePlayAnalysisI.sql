-- Last updated: 2/9/2026, 1:27:12 PM
# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;