SELECT order_id,
        product_id,
        TO_CHAR(out_date, 'YYYY-MM-DD') out_date,
        CASE
            WHEN out_date is NULL THEN '출고미정'
            WHEN out_date<=TO_DATE('2022-05-01','YYYY-MM-DD') THEN '출고완료'
            ELSE '출고대기'
        END "출고여부"
FROM food_order
ORDER BY order_id;
