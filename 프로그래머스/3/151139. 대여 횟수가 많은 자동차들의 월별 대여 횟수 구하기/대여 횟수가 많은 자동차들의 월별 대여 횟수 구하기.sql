SELECT      TO_NUMBER(TO_CHAR(START_DATE, 'MM')) AS MONTH,
            CAR_ID,
            COUNT(HISTORY_ID) AS RECORDS
FROM        CAR_RENTAL_COMPANY_RENTAL_HISTORY  
WHERE           START_DATE BETWEEN TO_DATE('2022-08-01', 'YYYY-MM-DD') 
                    AND TO_DATE('2022-10-31', 'YYYY-MM-DD')
                    AND CAR_ID IN (
                SELECT      CAR_ID
                FROM        CAR_RENTAL_COMPANY_RENTAL_HISTORY
                WHERE       START_DATE  BETWEEN TO_DATE('2022-08-01', 'YYYY-MM-DD')
                                            AND TO_DATE('2022-10-31', 'YYYY-MM-DD')
                GROUP BY    CAR_ID
                HAVING      COUNT(HISTORY_ID)>=5
            )
GROUP BY    TO_CHAR(START_DATE, 'MM'),
            CAR_ID
ORDER BY    TO_NUMBER(TO_CHAR(START_DATE, 'MM')) ASC,
            CAR_ID DESC