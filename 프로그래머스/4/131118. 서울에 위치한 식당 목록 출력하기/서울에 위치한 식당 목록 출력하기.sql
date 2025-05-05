WITH scores AS (
    SELECT
        rest_id,
        ROUND(AVG(review_score), 2) AS score
    FROM
        rest_review
    GROUP BY
        rest_id
)

SELECT
    i.rest_id,
    i.rest_name,
    i.food_type,
    i.favorites,
    i.address,
    s.score
FROM
    rest_info i
JOIN
    scores s ON i.rest_id=s.rest_id
WHERE
    SUBSTR(address, 1, 2)='서울'
ORDER BY
    s.score DESC,
    i.favorites DESC;
