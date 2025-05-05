SELECT
    COUNT(i.id) AS fish_count,
    ni.fish_name
FROM
    fish_info i
JOIN
    fish_name_info ni ON i.fish_type=ni.fish_type
GROUP BY
    i.fish_type,
    ni.fish_name
ORDER BY
    fish_count DESC;