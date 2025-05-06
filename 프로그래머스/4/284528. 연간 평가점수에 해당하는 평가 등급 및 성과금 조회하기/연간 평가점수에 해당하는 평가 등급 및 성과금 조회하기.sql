SELECT
    g.emp_no,
    e.emp_name,
    grade,
    CASE
    WHEN grade='S' THEN e.sal*20/100
    WHEN grade='A' THEN e.sal*15/100
    WHEN grade='B' THEN e.sal*10/100
    ELSE 0
    END AS bonus
FROM (
    SELECT 
        emp_no,
        CASE
        WHEN AVG(SCORE)>=96 THEN 'S'
        WHEN AVG(SCORE)>=90 THEN 'A'
        WHEN AVG(SCORE)>=80 THEN 'B'
        ELSE 'C'
        END AS grade
    FROM
        hr_grade
    GROUP BY
        emp_no
) g
JOIN
    hr_employees e ON g.emp_no=e.emp_no
ORDER BY
    e.emp_no ASC;