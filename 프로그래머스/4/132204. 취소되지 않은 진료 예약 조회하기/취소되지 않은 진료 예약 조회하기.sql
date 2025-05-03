SELECT
    a.apnt_no,
    p.pt_name,
    p.pt_no,
    a.mcdp_cd,
    d.dr_name,
    a.apnt_ymd
FROM
    appointment a
INNER JOIN
    doctor d ON a.mddr_id=d.dr_id
INNER JOIN
    patient p ON a.pt_no=p.pt_no
WHERE
    a.apnt_ymd BETWEEN TO_DATE('2022-04-13', 'YYYY-MM-DD') AND TO_DATE('2022-04-14', 'YYYY-MM-DD')
    AND a.apnt_cncl_yn='N'
    AND a.mcdp_cd='CS'
ORDER BY
    a.apnt_ymd ASC;