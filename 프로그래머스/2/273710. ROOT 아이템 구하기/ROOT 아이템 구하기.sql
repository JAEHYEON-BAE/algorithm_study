SELECT
    i.item_id,
    i.item_name
FROM
    item_tree t
JOIN
    item_info i ON t.item_id=i.item_id
WHERE
    t.parent_item_id IS NULL
ORDER BY
    i.item_id;