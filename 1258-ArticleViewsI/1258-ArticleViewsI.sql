-- Last updated: 2/9/2026, 1:27:07 PM
# Write your MySQL query statement below
SELECT viewer_id as id FROM Views 
WHERE viewer_id = author_id
GROUP BY viewer_id, author_id HAVING COUNT(*) >=1
order by viewer_id ASC;