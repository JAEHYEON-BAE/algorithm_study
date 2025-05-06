SELECT DISTINCT
    id,
    email,
    first_name,
    last_name
FROM
    developers d
JOIN
    skillcodes s ON d.skill_code&s.code!=0 AND s.category='Front End'
ORDER BY
    d.id ASC;