WITH
users AS (
    SELECT
        user_id
    FROM
        user_info
    WHERE
        TO_CHAR(joined, 'YYYY')='2021'
),
sales AS (
    SELECT
        DISTINCT os.user_id,
        TO_NUMBER(TO_CHAR(sales_date, 'YYYY')) AS year,
        TO_NUMBER(TO_CHAR(sales_date, 'MM')) AS month
    FROM
        online_sale os
    JOIN
        users u ON os.user_id=u.user_id
),
monthly_count AS (
    SELECT
        year,
        month,
        COUNT(DISTINCT user_id) AS purchased_users
    FROM 
        sales
    GROUP BY
        year,
        month
)

SELECT 
    year,
    month,
    purchased_users,
    ROUND(purchased_users/(
        SELECT COUNT(user_id) 
        FROM users
    ), 1) AS purchased_ratio
FROM
    monthly_count
ORDER BY
    year ASC,
    month ASC;

    