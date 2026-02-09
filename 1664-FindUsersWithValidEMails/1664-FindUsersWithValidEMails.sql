-- Last updated: 2/9/2026, 1:26:53 PM
# Write your MySQL query statement below
-- SELECT * FROM Users
-- WHERE mail REGEXP '^[a-zA-Z][a-zA-Z0-9\._\-]*@leetcode(\\?com)?\\.com' ;

SELECT * FROM Users
WHERE regexp_like(mail, '^[a-zA-Z]+[a-zA-Z0-9\.\_\-]*@leetcode(\\?com)?\\.com$', 'c');
