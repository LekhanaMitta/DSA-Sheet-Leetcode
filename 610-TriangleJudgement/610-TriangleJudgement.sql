-- Last updated: 2/9/2026, 1:27:55 PM
# Write your MySQL query statement below
SELECT x, y, z,
  CASE
    WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
    ELSE 'No'
  END AS triangle
FROM Triangle;
