SELECT
    TO_CHAR(sales_date, 'YYYY') AS year,
    TO_NUMBER(TO_CHAR(sales_date, 'MM')) AS month,
    gender,
    COUNT(DISTINCT online_sale.user_id) AS users
FROM
    online_sale
JOIN
    user_info ON online_sale.user_id=user_info.user_id
WHERE
    gender IS NOT NULL
GROUP BY
    TO_CHAR(sales_date, 'YYYY'),
    TO_CHAR(sales_date, 'MM'),
    gender
ORDER BY
    year ASC,
    month ASC,
    gender