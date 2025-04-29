-- 트럭 대여기록에서, 대여금액 , 대여기록ID
SELECT
    history_id,
    ROUND(
        (C.daily_fee * (RH.end_date-RH.start_date+1)) * (100-NVL(P.discount_rate, 0)) / 100
    ) AS fee
FROM
    car_rental_company_car C
JOIN
    car_rental_company_rental_history RH
    ON  C.car_id=RH.car_id
LEFT JOIN car_rental_company_discount_plan P
    ON  C.car_type=P.car_type 
        AND 
        (
            (
                (RH.end_date-RH.start_date+1)>=7 AND (RH.end_date-RH.start_date+1)<30 AND P.duration_type='7일 이상'
            ) OR
            (
                (RH.end_date-RH.start_date+1)>=30 AND (RH.end_date-RH.start_date+1)<90 AND P.duration_type='30일 이상'
            ) OR
            (
                (RH.end_date-RH.start_date+1)>=90 AND P.duration_type='90일 이상'
            )
        )
WHERE
    C.car_type='트럭'
ORDER BY
    fee DESC,
    RH.history_id DESC;