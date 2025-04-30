SELECT
    h.flavor
FROM
    first_half h
FULL OUTER JOIN
    july j
    ON  h.flavor=j.flavor
GROUP BY
    h.flavor
ORDER BY
    SUM(NVL(h.total_order, 0) + NVL(j.total_order, 0)) DESC
FETCH
    FIRST 3 ROWS ONLY;