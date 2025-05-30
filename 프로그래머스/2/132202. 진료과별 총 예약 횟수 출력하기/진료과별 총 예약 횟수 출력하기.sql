SELECT      MCDP_CD "진료과코드"
        ,   COUNT(*) "5월예약건수"
FROM        APPOINTMENT
WHERE       TO_CHAR(APNT_YMD, 'YYYY')='2022'
        AND TO_CHAR(APNT_YMD, 'MM')='05'
GROUP BY    MCDP_CD
ORDER BY    COUNT(*) ASC
        ,   MCDP_CD ASC;