-- Last updated: 2/9/2026, 1:27:15 PM
# Write your MySQL query statement below
SELECT actor_id, director_id FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3;
