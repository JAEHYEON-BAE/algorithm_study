WITH dept_salary AS (
    SELECT
        dept_id,
        ROUND(AVG(sal), 0) AS avg_sal
    FROM
        hr_employees
    GROUP BY
        dept_id
)

SELECT
    hd.dept_id,
    hd.dept_name_en,
    ds.avg_sal
FROM
    hr_department hd 
JOIN
    dept_salary ds ON hd.dept_id=ds.dept_id
ORDER BY
    ds.avg_sal DESC;