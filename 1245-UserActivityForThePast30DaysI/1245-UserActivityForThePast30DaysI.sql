-- Last updated: 2/9/2026, 1:27:08 PM
# Write your MySQL query statement below
SELECT activity_date as Day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date <= '2019-07-27' AND activity_date >= '2019-06-28'
GROUP BY activity_date HAVING COUNT(session_id) >= 1;