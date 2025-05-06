WITH RECURSIVE ancestry AS (
    SELECT
        id,
        parent_id,
        1 AS generation
    FROM ecoli_data
    WHERE parent_id IS NULL
    
    UNION ALL
    
    SELECT
        e.id,
        e.parent_id,
        a.generation+1
    FROM ecoli_data e
    JOIN ancestry a ON a.id=e.parent_id
)


SELECT 
    COUNT(id) AS count,
    generation
FROM
    ancestry
WHERE id NOT IN (
    SELECT DISTINCT parent_id
    FROM ecoli_data
    WHERE parent_id IS NOT NULL
)
GROUP BY
    generation
ORDER BY
    generation ASC;