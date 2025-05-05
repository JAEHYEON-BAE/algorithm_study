SELECT
    i.item_id,
    i.item_name,
    i.rarity
FROM
    item_tree t
JOIN
    item_info p ON t.parent_item_id=p.item_id
JOIN
    item_info i ON t.item_id=i.item_id
WHERE 
    p.rarity='RARE'   
ORDER BY
    item_id DESC;