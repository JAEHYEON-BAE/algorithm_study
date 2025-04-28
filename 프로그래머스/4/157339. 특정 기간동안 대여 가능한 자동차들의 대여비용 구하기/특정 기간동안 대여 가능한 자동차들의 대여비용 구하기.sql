SELECT  DISTINCT C.car_id,
        C.car_type,
        C.daily_fee*30*(100-TO_NUMBER(SUBSTR(DP.discount_rate, 1, 1)))/100 AS FEE
FROM    CAR_RENTAL_COMPANY_CAR C
JOIN    CAR_RENTAL_COMPANY_DISCOUNT_PLAN DP
    ON  C.car_type=DP.car_type
WHERE   (C.car_type='SUV' OR C.car_type='세단')
        AND DP.duration_type='30일 이상'
        AND C.car_id NOT IN (
            SELECT DISTINCT car_id
            FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
            WHERE start_date <= TO_DATE('2022-11-30', 'YYYY-MM-DD')
              AND end_date >= TO_DATE('2022-11-01', 'YYYY-MM-DD')
            )
        AND C.daily_fee*30*(100-TO_NUMBER(SUBSTR(DP.discount_rate, 1, 1)))/100 BETWEEN 500000 AND 1999999
ORDER BY    FEE DESC, C.car_type ASC, C.car_id DESC;