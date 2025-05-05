SELECT DISTINCT
    id,
    email,
    first_name,
    last_name
FROM
    developers d
JOIN
    skillcodes s ON d.skill_code & s.code != 0 
WHERE
    s.name='Python'
    OR s.name='C#'
ORDER BY
    id ASC;