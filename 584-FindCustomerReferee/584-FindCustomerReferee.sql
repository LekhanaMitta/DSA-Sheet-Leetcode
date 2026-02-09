-- Last updated: 2/9/2026, 1:27:59 PM
# Write your MySQL query statement below
SELECT name as Name FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL;