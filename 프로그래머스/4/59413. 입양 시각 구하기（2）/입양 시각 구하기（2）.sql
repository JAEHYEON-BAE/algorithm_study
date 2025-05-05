WITH hours AS (
    SELECT 
        LEVEL-1 AS hour
    FROM
        DUAL
    CONNECT BY
        LEVEL<=24
),
outs AS (
    SELECT
        TO_NUMBER(TO_CHAR(datetime, 'HH24')) AS hour,
        COUNT(animal_id) AS count
    FROM
        animal_outs
    GROUP BY
        TO_NUMBER(TO_CHAR(datetime, 'HH24'))
)

SELECT
    h.hour,
    NVL(o.count, 0)
FROM
    hours h
LEFT JOIN
    outs o ON h.hour=o.hour
ORDER BY
    h.hour;