SELECT
    cart_id
FROM
    cart_products
WHERE
    name='Milk'
    OR name='Yogurt'
GROUP BY
    cart_id
HAVING
    COUNT(DISTINCT name)>=2
ORDER BY
    cart_id ASC;