SELECT
    o.animal_id,
    o.name
FROM
    animal_ins  i
RIGHT JOIN
    animal_outs o
    ON  o.animal_id=i.animal_id
WHERE i.animal_id IS NULL
ORDER BY o.animal_id;