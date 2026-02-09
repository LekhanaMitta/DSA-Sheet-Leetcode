-- Last updated: 2/9/2026, 1:27:01 PM
# Write your MySQL query statement below
-- SELECT s.student_id, s.student_name, e.subject_name AS attended_exams FROM Students s
-- CROSS JOIN Examinations e ON s.student_id = e.student_id;
-- -- JOIN Subjects j ON e.subject_name = j.subject_name
-- GROUP BY subject_name, student_name
-- ORDER BY student_id;

SELECT s.student_id, s.student_name, j.subject_name, COUNT(e.subject_name) AS attended_exams  FROM Students s
CROSS JOIN subjects j
LEFT JOIN Examinations e ON e.student_id = s.student_id
AND e.subject_name = j.subject_name
GROUP BY student_name, subject_name, student_id
ORDER BY student_id, student_name, subject_name;

-- SELECT * FROM Students s
-- CROSS JOIN subjects j
-- LEFT JOIN Examinations e ON e.student_id = s.student_id;
-- GROUP BY student_name, subject_name
-- ORDER BY student_id;
