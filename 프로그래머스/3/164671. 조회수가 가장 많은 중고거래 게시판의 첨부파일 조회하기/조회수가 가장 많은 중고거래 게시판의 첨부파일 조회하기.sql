SELECT      '/home/grep/src/' || F.BOARD_ID || '/' || F.FILE_ID || F.FILE_NAME || FILE_EXT AS FILE_PATH
FROM        USED_GOODS_BOARD    B
JOIN        USED_GOODS_FILE     F
        ON  B.BOARD_ID=F.BOARD_ID
WHERE       B.VIEWS = (
                SELECT      MAX(VIEWS)
                FROM        USED_GOODS_BOARD
            )
ORDER BY    F.FILE_ID DESC;