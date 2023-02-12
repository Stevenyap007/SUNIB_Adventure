-- no 1 create

CREATE TABLE MsStaff (
    Staffid CHAR(4) PRIMARY KEY CHECK(Staffid REGEXP 'S[0-9][0-9][0-9]'),
    StaffName VARCHAR(100) NOT NULL,
    StaffGender VARCHAR(6) NOT NULL,
    StaffAddress VARCHAR(100) NOT NULL CHECK(StaffAddress LIKE '% street')
)

-- no 2 insert

INSERT INTO MsStaff VALUES
('S001', 'Mark Zulcan Vinesca', 'Male', 'Andamite 15 street')

-- no 3 display

SELECT 
	a.AlbumID,
    a.AlbumName,
    t.ArtistName,
    t.ArtistNationality
    
FROM msalbum a JOIN msartist t ON a.ArtistID = t.ArtistID
WHERE t.ArtistGender LIKE 'Male';

-- no 4

SELECT 
	h.TransactionId,
    h.TransactionDate,
    d.AlbumId,
    d.Quantity,
    c.CustomerName,
    LEFT(c.CustomerGender, LOCATE('', c.CustomerGender)) AS Gender
    

FROM trheadertransaction h JOIN trdetailtransaction d ON h.TransactionId = d.TransactionId
JOIN mscustomer c ON h.CustomerId = c.CustomerID
WHERE YEAR(c.CustomerDOB) = 1990 AND d.Quantity > 10

-- no 5

DELETE FROM msartist t JOIN msalbum a ON t.ArtistID = a.ArtistID

WHERE CHAR_LENGTH(ArtistName) > 22;
