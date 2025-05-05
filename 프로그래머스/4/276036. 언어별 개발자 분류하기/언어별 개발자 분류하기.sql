WITH
front_end AS (
    SELECT code
    FROM skillcodes
    WHERE category='Front End'
),
class_a AS (
    SELECT DISTINCT d.id
    FROM developers d
    JOIN skillcodes s ON d.skill_code&s.code!=0 AND s.name='Python'
    JOIN front_end f ON d.skill_code&f.code!=0
),
class_b AS (
    SELECT DISTINCT d.id
    FROM developers d
    JOIN skillcodes s ON d.skill_code&s.code!=0 AND s.name='C#'
    # JOIN front_end f ON d.skill_code&f.code!=0
    # WHERE d.id NOT IN (
    #     SELECT id
    #     FROM class_a
    # )
),
class_c AS (
    SELECT DISTINCT d.id
    FROM developers d
    JOIN front_end f ON d.skill_code&f.code!=0
    WHERE d.id NOT IN (
        SELECT id
        FROM class_a
    )
    AND d.id NOT IN (
        SELECT id
        FROM class_b
    )
)

SELECT
    'A' AS grade,
    id,
    email
FROM 
    developers
WHERE
    id IN (
        SELECT id
        FROM class_a
    )

UNION ALL

SELECT
    'B' AS grade,
    id,
    email
FROM
    developers
WHERE
    id IN (
        SELECT id
        FROM class_b
    )
    
UNION ALL

SELECT
    'C' AS grade,
    id,
    email
FROM
    developers
WHERE
    id IN (
        SELECT id
        FROM class_c
    )
ORDER BY
    grade ASC,
    id ASC;