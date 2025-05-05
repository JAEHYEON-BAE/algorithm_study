SELECT
    c.id,
    c.genotype,
    p.genotype AS parent_genotype
FROM
    ecoli_data c
JOIN
    ecoli_data p ON c.parent_id=p.id
WHERE
    c.genotype | p.genotype = c.genotype
ORDER BY
    c.id ASC;
