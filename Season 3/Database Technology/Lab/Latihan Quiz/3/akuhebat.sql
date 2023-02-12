--NO 1
CREATE TABLE MsStaff(
    StaffId CHAR(4) PRIMARY KEY CHECK(StaffId REGEXP '^S[0-9][0-9][0-9]'),
    StaffName VARCHAR(100) NOT NULL,
    StaffGender VARCHAR(6) NOT NULL,
    StaffAddress VARCHAR(100) NOT NULL CHECK(StaffAddress LIKE'% street')
);

--NO 2
INSERT INTO msstaff VALUES (
'S001','Mark Zulcan Vinesca','Male','Andamite 15 street'
);

--No 3
SELECT ma.AlbumID,
ma.AlbumName,
mr.ArtistName,
mr.ArtistNationality
FROM msalbum ma JOIN msartist mr
	ON ma.ArtistID = mr.ArtistID
WHERE mr.ArtistGender LIKE 'male';

--No 4
SELECT tr.TransactionId,
tr.TransactionDate,
td.AlbumId,
td.Quantity,
mc.CustomerName,
LEFT(mc.CustomerGender,1)
FROM trheadertransaction AS tr jOIN trdetailtransaction AS td
	ON tr.TransactionId =td.TransactionId JOIN mscustomer AS mc
    ON tr.CustomerId = mc.CustomerID
WHERE YEAR(mc.CustomerDOB) = 1990 AND td.Quantity > 10;

--No. 5
DELETE FROM msalbum 
WHERE ArtistID IN (SELECT ArtistID FROM msartist WHERE CHAR_LENGTH(ArtistName) > 22);

--atau
DELETE ma FROM msalbum ma JOIN msartist mr
    ON ma.ArtistID = mr.ArtistID
WHERE CHAR_LENGTH(mr.ArtistName) > 22;