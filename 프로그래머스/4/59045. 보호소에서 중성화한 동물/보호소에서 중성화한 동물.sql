SELECT
    animal_id,
    animal_type,
    name
FROM
    animal_ins
WHERE
    animal_id IN (
        SELECT
            animal_id
        FROM
            animal_outs
        WHERE
            sex_upon_outcome LIKE '%Spayed%'
            OR sex_upon_outcome LIKE '%Neutered%'
        )
    AND sex_upon_intake LIKE '%Intact%'
ORDER BY
    animal_id ASC;