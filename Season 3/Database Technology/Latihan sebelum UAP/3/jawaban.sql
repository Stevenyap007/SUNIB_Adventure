--1
use latihan1

--2
SELECT
th.transactionid `Transaction ID`,
mc.customername `Customer Name`,
th.transactiondate `Transaction Date`
FROM
mscustomer as mc JOIN
transactionheader as th ON th.customerid = mc.customerid
WHERE YEAR(th.transactiondate) = '2022';

--3
SELECT
mc.creatorname `CreatorName`,
ms.stickername `StickerName`,
CONCAT('$ ', ms.stickerprice) `StickerPrice`
FROM
mscreator as mc JOIN
mssticker as ms ON ms.creatorid = mc.creatorid
WHERE mc.creatorname LIKE 'M%'
UNION
SELECT
mc.creatorname `CreatorName`,
ms.stickername `StickerName`,
CONCAT('$ ', ms.stickerprice) `StickerPrice`
FROM
mscreator as mc JOIN
mssticker as ms ON ms.creatorid = mc.creatorid
WHERE mc.creatorname LIKE 'J%'

--4
SELECT
REPLACE (th.transactionid, "TR", "Transaction-") `TransactionID`,
ms.stickername `StickerName`,
UPPER(mc.customername) `CustomerName`,
td.quantity `Quantity`
FROM
transactionheader as th JOIN
transactiondetail as td ON th.transactionid = td.transactionid JOIN
mssticker as ms ON ms.stickerid = td.stickerid JOIN
mscustomer as mc ON mc.customerid = th.customerid
WHERE 
ms.stickername LIKE '%PopUp%' AND
mc.customername LIKE '% %'
UNION
SELECT
REPLACE (th.transactionid, "TR", "Transaction-") `TransactionID`,
ms.stickername `StickerName`,
UPPER(mc.customername) `CustomerName`,
td.quantity `Quantity`
FROM
transactionheader as th JOIN
transactiondetail as td ON th.transactionid = td.transactionid JOIN
mssticker as ms ON ms.stickerid = td.stickerid JOIN
mscustomer as mc ON mc.customerid = th.customerid
WHERE 
ms.stickername LIKE '%Mini%' AND
mc.customername LIKE '% %'

--5
ALTER TABLE mssticker
ADD COLUMN StickerCategory CHAR(10)
CHECK (StickerCategory IN('Fanmade', 'Official'))

--6
DELETE FROM
mscustomer
WHERE customername LIKE 'H%' AND
customerid IN(
    SELECT customerid
    FROM transactionheader
    WHERE YEAR(transactiondate) = '2022'    
);

--7
SELECT
DATE_FORMAT(th.transactiondate, "%a, %D %b %Y")`TransactionDate`,
mc.creatorname `CreatorName`,
ms.stickername `StickerName`,
td.quantity `QuantityBought`,
ms.stickerprice `StickerPrice`,
(td.quantity * ms.stickerprice) `TotalPrice`
FROM transactionheader as th JOIN
transactiondetail as td ON td.transactionid = th.transactionid JOIN
mssticker as ms ON ms.stickerid = td.stickerid JOIN
mscreator as mc ON mc.creatorid = ms.creatorid
WHERE mc.creatorid IN('CR003', 'CR004')
AND (td.quantity * ms.stickerprice) > 35000

--8
SELECT 
RIGHT(td.transactionid, 3) `TransactionNumber`,
ms.stickerid `StickerID`,
ms.stickername `StickerName`,
td.quantity `Quantity`
FROM
transactiondetail td JOIN
mssticker ms ON
td.stickerid = ms.stickerid
ORDER BY td.transactionid DESC

--9
CREATE VIEW viewFirstWordFromStickerName AS
SELECT ms.stickerid `StickerID`,
mc.creatorname `CreatorName`,
SUBSTRING(ms.stickername, 1 ,LOCATE(" ", ms.stickername) - 1) `StickerName`
FROM mssticker ms
JOIN mscreator mc ON mc.creatorid = ms.creatorid

--10
SELECT
REPLACE(td.transactionid, "TR", "Transaction-") `TransactionID`,
CONCAT_WS("-", mc.creatorname, UPPER(ms.stickername)) `StickerDescription`,
td.quantity `QuantityBought`
FROM
transactiondetail td JOIN
mssticker ms ON ms.stickerid = td.stickerid JOIN
mscreator mc ON mc.creatorid = ms.creatorid