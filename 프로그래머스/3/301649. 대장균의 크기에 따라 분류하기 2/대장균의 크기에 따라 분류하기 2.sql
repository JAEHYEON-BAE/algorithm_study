SELECT
    id,
    CASE
        WHEN rn<=total/4 THEN 'CRITICAL'
        WHEN rn<=total/2 THEN 'HIGH'
        WHEN rn<=3*total/4 THEN 'MEDIUM'
        ELSE 'LOW'
    END AS colony_name
FROM (
    SELECT 
        id, 
        ROW_NUMBER() OVER (ORDER BY size_of_colony DESC) AS rn,
        COUNT(id) OVER () AS total
    FROM ecoli_data
) des
ORDER BY
    id ASC;
