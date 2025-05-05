SELECT
    p.product_id,
    p.product_name,
    SUM(o.amount*p.price) AS total_sales
FROM
    food_product p
JOIN
    food_order o ON p.product_id=o.product_id
WHERE
    TO_CHAR(o.produce_date, 'YYYY-MM')='2022-05'
GROUP BY
    p.product_id,
    p.product_name
ORDER BY
    total_sales DESC,
    p.product_id ASC;