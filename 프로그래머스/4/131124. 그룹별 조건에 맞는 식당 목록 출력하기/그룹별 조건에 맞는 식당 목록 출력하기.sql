SELECT
    member_name,
    review_text,
    TO_CHAR(review_date, 'YYYY-MM-DD') AS review_date
FROM
    rest_review r
JOIN 
    member_profile m ON r.member_id=m.member_id
WHERE
    r.member_id = (
        SELECT
            member_id
        FROM
            rest_review
        GROUP BY
            member_id
        ORDER BY
            COUNT(review_id) DESC
        FETCH
            FIRST 1 ROW ONLY
    )
ORDER BY
    r.review_date