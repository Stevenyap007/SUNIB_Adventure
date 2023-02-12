CREATE TABLE mscustomer(
    customerid char(5) PRIMARY KEY,
    customergender varchar(10),
    customername varchar(50),
    customeremail varchar(50),
    customerdob date
);

CREATE TABLE transactionheader(
    transactionid char(5) PRIMARY KEY,
    customerid char(50) ,
    transactiondate date,
    FOREIGN KEY(customerid) REFERENCES mscustomer(customerid) on update cascade on delete cascade
);

CREATE TABLE mscreator(
    creatorid char(5) PRIMARY KEY,
    creatorname char(50),
    creatoremail varchar(50),
    creatorgender varchar(50)
);

CREATE TABLE mssticker(
    stickerid char(5) PRIMARY KEY,
    creatorid char(5) ,
    stickername varchar(50),
    stickerprice integer(10),
    FOREIGN KEY(creatorid)  REFERENCES mscreator(creatorid) on update cascade on delete cascade
);

CREATE TABLE transactiondetail(
    transactionid char(5) ,
    stickerid char(5) ,
    quantity integer(10),
    FOREIGN KEY (transactionid) REFERENCES transactionheader(transactionid) on update cascade on delete cascade,
    FOREIGN KEY (stickerid) REFERENCES mssticker(stickerid) on update cascade on delete cascade,

    PRIMARY KEY(transactionid, stickerid)
); 

INSERT INTO mscreator VALUES
("CR001","Matcha Poyo","matcha.poyo@email.com","Female"),
("CR002","Jevil Saipudin","jevil.saipudin@email.com","Male"),
("CR003","Rogue Shoto","r.shoto@email.com","Male"),
("CR004","Muwujak Evewgawden","mujak.violet@email.com","Male"),
("CR005","Luana","luana@email.com","Female"),
("CR006","Aiyuu Honey","aiyuu.honey@email.com","Male"),
("CR007","Cathy Belvanita","cathy.belvanita@email.com","Female"),
("CR008","Jake Iskandar","jake.iskandar@email.com","Male"),
("CR009","Vito Lycoris","vito.lycoris@email.com","Male"),
("CR010","TinTin","tintin@email.com","Female");


INSERT INTO mscustomer VALUES
("CU001","Male","Hady Gustianto","hady.gustianto@email.com","2003-10-09"),
("CU002","Female","Gratia Honestha Patiung","gratia.honestha@email.com","2004-05-16"),
("CU003","Male","Anthony William Chandra","anthony.willchan@email.com","2001-05-26"),
("CU004","Male","Budiman Wijaya","budiman.wijaya@email.com","2000-11-19"),
("CU005","Female","Holyvia Marcella","holyvia.marcella@email.com","2003-09-11"),
("CU006","Male","Arya","arya@email.com","2000-10-14"),
("CU007","Male","Jason","jason@email.com","2002-01-06"),
("CU008","Male","Wiryahadi Gunawan","wiryahudi@email.com","2002-09-06"),
("CU009","Male","Tegar Abdullah","tegar.abdullah@email.com","2000-12-03"),
("CU010","Male","Jordy Wira Arta","jordy.arta@email.com","2000-04-09"); 
INSERT INTO mssticker VALUES 
("SR001","CR001","ORV Sticker",15000),
("SR002","CR001","Kajuu Animated Sticker",35000),
("SR003","CR003","Shoto Animated Sticker",35000),
("SR004","CR002","Senopati Sticker",15000),
("SR005","CR004","Viowet PopUp Sticker",45000),
("SR006","CR007","Diwuc Animated Sticker",35000),
("SR007","CR008","It's Jake Sticker",15000),
("SR008","CR008","Bubble Man Mini Sticker",10000),
("SR009","CR009","Potato Meme Sticker",15000),
("SR010","CR009","City Girl Animated Sticker",35000),
("SR011","CR010","Egg Man Meme Sticker",15000),
("SR012","CR001","Mika Mini Sticker",10000),
("SR013","CR003","Shoto Doggy Large Sticker",40000),
("SR014","CR002","Jogging Jevil PopUp Sticker",45000),
("SR015","CR004","Coco Mini Sticker",10000);

INSERT INTO transactionheader VALUES
("TR001","CU001","2021-02-03"),
("TR002","CU002","2021-03-25"),
("TR003","CU003","2021-04-01"),
("TR004","CU004","2021-05-06"),
("TR005","CU001","2021-06-05"),
("TR006","CU003","2021-07-08"),
("TR007","CU004","2021-08-16"),
("TR008","CU005","2021-09-20"),
("TR009","CU007","2021-10-01"),
("TR010","CU009","2021-11-12"),
("TR011","CU003","2021-12-01"),
("TR012","CU005","2022-03-05"),
("TR013","CU004","2022-04-04"),
("TR014","CU003","2022-05-19"),
("TR015","CU002","2022-08-23"); 
INSERT INTO transactiondetail VALUES
("TR001","SR001",2),
("TR001","SR002",2),
("TR002","SR004",1),
("TR002","SR006",1),
("TR002","SR007",1),
("TR003","SR003",3),
("TR003","SR006",2),
("TR004","SR010",2),
("TR005","SR008",1),
("TR006","SR007",2),
("TR007","SR006",2),
("TR008","SR006",3),
("TR009","SR003",1),
("TR009","SR002",1),
("TR010","SR001",1),
("TR011","SR001",1),
("TR011","SR002",1),
("TR012","SR006",2),
("TR012","SR005",1),
("TR013","SR002",1),
("TR013","SR003",1),
("TR014","SR004",2),
("TR014","SR006",3),
("TR014","SR007",1),
("TR015","SR002",2);