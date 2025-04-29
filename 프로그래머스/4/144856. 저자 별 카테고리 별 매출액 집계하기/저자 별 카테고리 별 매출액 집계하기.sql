SELECT  
    A.author_id,
    A.author_name,
    B.category,
    SUM(B.PRICE * BS.sales) AS total_sales
FROM
    book B
JOIN
    book_sales BS
    ON  B.book_id=BS.book_id
JOIN
    author A
    ON  B.author_id=A.author_id
WHERE
    BS.sales_date BETWEEN TO_DATE('2022-01-01', 'YYYY-MM-DD') AND TO_DATE('2022-01-31', 'YYYY-MM-DD')
GROUP BY 
    A.author_id,
    A.author_name,
    B.category
ORDER BY
    author_id ASC,
    category DESC;