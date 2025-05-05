SELECT
    f.id,
    n.fish_name,
    f.length
FROM (
    SELECT
        id,
        length,
        fish_type,
        ROW_NUMBER() OVER (
            PARTITION BY fish_type
            ORDER BY length DESC
        ) AS rn
    FROM
        fish_info
) AS f
JOIN
    fish_name_info n ON f.fish_type=n.fish_type
WHERE
    rn=1
ORDER BY
    f.id ASC;
