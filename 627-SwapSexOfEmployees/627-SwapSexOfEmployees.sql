-- Last updated: 2/9/2026, 1:27:51 PM
# Write your MySQL query statement below
UPDATE salary 
SET sex = (CASE WHEN sex = 'f' THEN 'm' ELSE 'f' END);