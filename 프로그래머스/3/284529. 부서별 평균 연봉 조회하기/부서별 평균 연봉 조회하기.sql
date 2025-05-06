SELECT
    hd.dept_id,
    hd.dept_name_en,
    ROUND(AVG(he.sal), 0) AS avg_sal
FROM
    hr_department hd
INNER JOIN
    hr_employees he ON hd.dept_id=he.dept_id
GROUP BY
    hd.dept_id
ORDER BY
    AVG(he.sal) DESC;