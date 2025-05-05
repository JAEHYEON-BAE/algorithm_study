SELECT
    e.id
FROM
    ecoli_data e
JOIN
    ecoli_data pe ON e.parent_id=pe.id
JOIN
    ecoli_data ppe ON pe.parent_id=ppe.id
WHERE
    ppe.parent_id IS NULL
ORDER BY
    e.id ASC;