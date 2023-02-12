-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 03, 2022 at 05:17 PM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 7.3.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `jetify`
--

-- --------------------------------------------------------

--
-- Table structure for table `msalbum`
--

CREATE TABLE `msalbum` (
  `AlbumID` char(5) NOT NULL CHECK (`AlbumID` regexp 'AL[0-9][0-9][0-9]'),
  `ArtistID` char(5) DEFAULT NULL,
  `AlbumName` varchar(100) NOT NULL,
  `Duration` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `msalbum`
--

INSERT INTO `msalbum` (`AlbumID`, `ArtistID`, `AlbumName`, `Duration`) VALUES
('AL001', 'AR007', 'Boom', 243),
('AL002', 'AR003', 'Daridari', 219),
('AL003', 'AR004', 'T_T', 236),
('AL004', 'AR004', 'Door Knock', 306),
('AL005', 'AR006', 'BDZ', 272),
('AL006', 'AR007', 'Forever Young', 219),
('AL007', 'AR004', 'Elephant', 340),
('AL008', 'AR009', 'Love is You', 198),
('AL009', 'AR005', 'Sand Castle', 250),
('AL010', 'AR007', 'When we are still young', 289),
('AL011', 'AR008', 'Shark do do', 219),
('AL012', 'AR006', '(X_X)', 328),
('AL013', 'AR003', 'Barbie Girl', 198),
('AL014', 'AR006', 'Blueming', 289),
('AL015', 'AR010', 'Sunshine', 265),
('AL016', 'AR004', 'Moonlight', 257),
('AL017', 'AR010', 'Dynamite', 235),
('AL018', 'AR010', 'Permission to Dance', 354),
('AL019', 'AR003', 'Color', 212),
('AL020', 'AR001', 'Maybe Today', 327);

-- --------------------------------------------------------

--
-- Table structure for table `msartist`
--

CREATE TABLE `msartist` (
  `ArtistID` char(5) NOT NULL CHECK (`ArtistID` regexp 'AR[0-9][0-9][0-9]'),
  `ArtistName` varchar(100) NOT NULL,
  `ArtistNationality` varchar(100) NOT NULL,
  `ArtistGender` varchar(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `msartist`
--

INSERT INTO `msartist` (`ArtistID`, `ArtistName`, `ArtistNationality`, `ArtistGender`) VALUES
('AR001', 'Neelie Quindell Kirra', 'Indonesia', 'Female'),
('AR002', 'Tynika Vena Jourdan', 'Japan', 'Female'),
('AR003', 'Nery Ivan Tyleen', 'Korea', 'Male'),
('AR004', 'Brendin Cresencio Tacarra', 'Indonesia', 'Female'),
('AR005', 'Cena Cortina Tisheena', 'China', 'Female'),
('AR006', 'Darrow Cris Shalom', 'Western', 'Female'),
('AR007', 'Kennesha Kitty Travonne', 'Indonesia', 'Male'),
('AR008', 'Amirah Ugo Krissa', 'Korea', 'Female'),
('AR009', 'Jaie Avian Michaeal', 'Korea', 'Female'),
('AR010', 'Cullen Ashante Raheem', 'Indonesia', 'Male');

-- --------------------------------------------------------

--
-- Table structure for table `mscustomer`
--

CREATE TABLE `mscustomer` (
  `CustomerID` char(5) NOT NULL CHECK (`CustomerID` regexp 'CU[0-9][0-9][0-9]'),
  `CustomerName` varchar(100) NOT NULL,
  `CustomerEmail` varchar(100) NOT NULL,
  `CustomerDOB` date NOT NULL,
  `CustomerGender` varchar(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `mscustomer`
--

INSERT INTO `mscustomer` (`CustomerID`, `CustomerName`, `CustomerEmail`, `CustomerDOB`, `CustomerGender`) VALUES
('CU001', 'Sharnay Kongmeng Tamia', 'Sharnay444250@gmail.com', '1990-02-07', 'Female'),
('CU002', 'Lashunda Marylee Jaira', 'Lashunda@gmail.com', '1980-06-19', 'Female'),
('CU003', 'Nahum Avid Laportia', 'Nahum514550@gmail.com', '1989-03-08', 'Female'),
('CU004', 'Dimitrios Michala Tocara', 'Dimitrios505557@gmail.com', '1981-02-13', 'Male'),
('CU005', 'Boruch Orestes Adalberto', 'Boruch4745@gmail.com', '1995-11-05', 'Female'),
('CU006', 'Joaquim Caralynn Calder', 'Joaquim@gmail.com', '1999-11-19', 'Male'),
('CU007', 'Shanterria Shamara Drayton', 'Shanterria@gmail.com', '1983-03-20', 'Male'),
('CU008', 'Leneisha Candra Kary', 'Leneisha48@gmail.com', '1980-11-25', 'Female'),
('CU009', 'Sheelah Yaakov Halbert', 'Sheelah@gmail.com', '2000-10-02', 'Male'),
('CU010', 'Dominek Babajide Damany', 'Dominek@gmail.com', '1995-08-14', 'Male');

-- --------------------------------------------------------

--
-- Table structure for table `trdetailtransaction`
--

CREATE TABLE `trdetailtransaction` (
  `TransactionId` char(5) NOT NULL,
  `AlbumId` char(5) NOT NULL,
  `Quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `trdetailtransaction`
--

INSERT INTO `trdetailtransaction` (`TransactionId`, `AlbumId`, `Quantity`) VALUES
('TR001', 'AL005', 14),
('TR001', 'AL006', 14),
('TR002', 'AL002', 10),
('TR002', 'AL006', 4),
('TR003', 'AL008', 13),
('TR004', 'AL001', 11),
('TR004', 'AL005', 7),
('TR004', 'AL006', 3),
('TR004', 'AL007', 5),
('TR005', 'AL004', 13),
('TR006', 'AL004', 4),
('TR007', 'AL004', 15),
('TR007', 'AL008', 9),
('TR008', 'AL003', 5),
('TR008', 'AL004', 8),
('TR009', 'AL004', 11),
('TR009', 'AL007', 13),
('TR010', 'AL007', 4),
('TR010', 'AL010', 14),
('TR011', 'AL004', 5);

-- --------------------------------------------------------

--
-- Table structure for table `trheadertransaction`
--

CREATE TABLE `trheadertransaction` (
  `TransactionId` char(5) NOT NULL CHECK (`TransactionId` regexp 'TR[0-9][0-9][0-9]'),
  `CustomerId` char(5) DEFAULT NULL,
  `TransactionDate` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `trheadertransaction`
--

INSERT INTO `trheadertransaction` (`TransactionId`, `CustomerId`, `TransactionDate`) VALUES
('TR001', 'CU005', '2022-01-28 00:00:00'),
('TR002', 'CU002', '2022-02-13 00:00:00'),
('TR003', 'CU002', '2022-02-21 00:00:00'),
('TR004', 'CU005', '2022-03-07 00:00:00'),
('TR005', 'CU001', '2022-04-15 00:00:00'),
('TR006', 'CU001', '2022-05-11 00:00:00'),
('TR007', 'CU001', '2022-05-16 00:00:00'),
('TR008', 'CU007', '2022-06-03 00:00:00'),
('TR009', 'CU002', '2022-06-18 00:00:00'),
('TR010', 'CU008', '2022-07-13 00:00:00'),
('TR011', 'CU009', '2022-07-19 00:00:00');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `msalbum`
--
ALTER TABLE `msalbum`
  ADD PRIMARY KEY (`AlbumID`),
  ADD KEY `ArtistID` (`ArtistID`);

--
-- Indexes for table `msartist`
--
ALTER TABLE `msartist`
  ADD PRIMARY KEY (`ArtistID`);

--
-- Indexes for table `mscustomer`
--
ALTER TABLE `mscustomer`
  ADD PRIMARY KEY (`CustomerID`);

--
-- Indexes for table `trdetailtransaction`
--
ALTER TABLE `trdetailtransaction`
  ADD PRIMARY KEY (`TransactionId`,`AlbumId`),
  ADD KEY `AlbumId` (`AlbumId`);

--
-- Indexes for table `trheadertransaction`
--
ALTER TABLE `trheadertransaction`
  ADD PRIMARY KEY (`TransactionId`),
  ADD KEY `CustomerId` (`CustomerId`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `msalbum`
--
ALTER TABLE `msalbum`
  ADD CONSTRAINT `msalbum_ibfk_1` FOREIGN KEY (`ArtistID`) REFERENCES `msartist` (`ArtistID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `trdetailtransaction`
--
ALTER TABLE `trdetailtransaction`
  ADD CONSTRAINT `trdetailtransaction_ibfk_1` FOREIGN KEY (`TransactionId`) REFERENCES `trheadertransaction` (`TransactionId`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trdetailtransaction_ibfk_2` FOREIGN KEY (`AlbumId`) REFERENCES `msalbum` (`AlbumID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `trheadertransaction`
--
ALTER TABLE `trheadertransaction`
  ADD CONSTRAINT `trheadertransaction_ibfk_1` FOREIGN KEY (`CustomerId`) REFERENCES `mscustomer` (`CustomerID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
