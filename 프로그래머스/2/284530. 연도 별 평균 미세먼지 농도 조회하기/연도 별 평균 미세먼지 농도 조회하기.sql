SELECT
    YEAR(ym) AS year,
    ROUND(AVG(pm_val1), 2) "pm10",
    ROUND(AVG(pm_val2), 2)"pm2.5"
FROM
    air_pollution
WHERE
    location1='경기도' AND location2='수원'
GROUP BY
    YEAR(ym)
ORDER BY
    year ASC;