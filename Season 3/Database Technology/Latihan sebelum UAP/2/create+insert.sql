-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 01, 2022 at 04:05 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gramediah`
--

-- --------------------------------------------------------

--
-- Table structure for table `msbook`
--

CREATE TABLE `msbook` (
  `BookID` char(5) NOT NULL,
  `BookTitle` varchar(50) NOT NULL,
  `BookPublishedDate` date NOT NULL,
  `BookAuthorName` varchar(50) NOT NULL,
  `BookPublisherName` varchar(50) NOT NULL,
  `BookPrice` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `msbook`
--

INSERT INTO `msbook` (`BookID`, `BookTitle`, `BookPublishedDate`, `BookAuthorName`, `BookPublisherName`, `BookPrice`) VALUES
('BO001', 'The Hunger Games', '1994-11-18', 'Suzanne Collins', 'HarperCollins Publishers', 76000),
('BO002', 'Catching Fire', '1972-03-25', 'Suzanne Collins', 'HarperCollins Publishers', 158558),
('BO003', 'Harry Potter and The Goblet of Fire', '2012-03-15', 'J.K. Rowling', 'Pearson', 150000),
('BO004', 'Learn Basic Math', '1970-03-18', 'Sakti Dimas Pradipta', 'Gramedia', 76000),
('BO005', 'They Came to Baghdad', '2014-05-09', 'Agatha Christie', 'Pearson', 688700),
('BO006', 'Learn Java Basic', '1981-07-25', 'Citra Yulia Purnawati', 'Gramedia', 70000),
('BO007', 'How to Learn Programming', '1971-12-03', 'Elma Nasyidah', 'Gramedia', 64000),
('BO008', 'Death on the Nile', '1985-10-01', 'Agatha Christie', 'Pearson', 66000),
('BO009', '7 Friends', '2014-04-08', 'Hardana Sitorus', 'Gramedia', 35000),
('BO010', 'Anne of Green Gables', '1908-04-23', 'L.M. Montgomery', 'HarperCollins Publishers', 80000);

-- --------------------------------------------------------

--
-- Table structure for table `mscustomer`
--

CREATE TABLE `mscustomer` (
  `CustomerID` char(5) NOT NULL,
  `CustomerName` varchar(50) NOT NULL,
  `CustomerPhoneNumber` varchar(18) NOT NULL,
  `CustomerAddress` varchar(100) NOT NULL,
  `CustomerDOB` date NOT NULL,
  `CustomerGender` varchar(7) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `mscustomer`
--

INSERT INTO `mscustomer` (`CustomerID`, `CustomerName`, `CustomerPhoneNumber`, `CustomerAddress`, `CustomerDOB`, `CustomerGender`) VALUES
('CU001', 'Cindy Azalea Mardhiyah', '0857419256591', 'Juanda Street No. 133', '1984-02-08', 'Female'),
('CU002', 'Galiono Caket Siregar', '082149360570', 'Agus Salim Street No. 170', '2008-05-18', 'Male'),
('CU003', 'Yulia Cinthia Permata', '085502301009', 'Kalimantan Street No. 438', '2001-11-05', 'Female'),
('CU004', 'Septi Nurdiyanti', '089925405292', 'Bakin Street No. 986', '2002-10-22', 'Female'),
('CU005', 'Jagapati Vega Salahudin', '084739656070', 'Bagonwoto Street No. 855', '1999-05-18', 'Male'),
('CU006', 'Narji Siregar', '082924676989', 'Taman Street No. 114', '2012-10-26', 'Male'),
('CU007', 'Anastasia Utami', '0845284993757', 'Adisucipto Street No. 703', '1983-09-15', 'Female'),
('CU008', 'Ani Purwanti', '087139418199', 'Suniaraja Street No. 509', '1982-06-19', 'Female'),
('CU009', 'Sabrina Puti Hassanah', '0894708863225', 'Krakatau Street No. 58', '1984-10-02', 'Female'),
('CU010', 'Nadine Pudjiastuti', '0826817755982', 'Cihampelas Street No. 115', '1983-02-24', 'Female');

-- --------------------------------------------------------

--
-- Table structure for table `msstaff`
--

CREATE TABLE `msstaff` (
  `StaffID` char(5) NOT NULL,
  `StaffName` varchar(50) NOT NULL,
  `StaffAddress` varchar(100) NOT NULL,
  `StaffDOB` date NOT NULL,
  `StaffPhoneNumber` varchar(18) NOT NULL,
  `StaffGender` varchar(7) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `msstaff`
--

INSERT INTO `msstaff` (`StaffID`, `StaffName`, `StaffAddress`, `StaffDOB`, `StaffPhoneNumber`, `StaffGender`) VALUES
('ST001', 'Ganep Lukita Simanjuntak', 'Diponegoro Street No. 392', '1986-01-15', '087251005213', 'Male'),
('ST002', 'Salimah Jasmin Novitasari', 'Bakau Griya Utama Street No. 816', '2012-01-24', '086006286533', 'Female'),
('ST003', 'Asirwada Lazuardi', 'Bacang Street No. 854', '1976-02-18', '0827675450066', 'Male'),
('ST004', 'Kala Hutagalung', 'Nanas Street No. 830', '1985-04-05', '082658448914', 'Male'),
('ST005', 'Ajiono Mahendra', 'Arifin Street No. 367', '2000-09-14', '0848102203652', 'Male'),
('ST006', 'Almira Ulya Rahimah', 'Suharso Street No. 71', '2006-01-30', '082481942723', 'Female'),
('ST007', 'Azalea Lestari', 'Otista Street No. 406', '2005-11-02', '08216275994', 'Female'),
('ST008', 'Maryanto Mulyono Salahudin', 'Imam Street No. 354', '1996-10-07', '0840054424974', 'Male'),
('ST009', 'Eko Saragih', 'Teuku Umar Street No. 391', '1981-05-31', '082288809153', 'Male'),
('ST010', 'Padmi Azalea Permata', 'Cjokroaminoto Street No. 990', '1976-04-19', '082745269887', 'Female');

-- --------------------------------------------------------

--
-- Table structure for table `transactiondetail`
--

CREATE TABLE `transactiondetail` (
  `TransactionID` char(5) NOT NULL,
  `BookID` char(5) NOT NULL,
  `Quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transactiondetail`
--

INSERT INTO `transactiondetail` (`TransactionID`, `BookID`, `Quantity`) VALUES
('TR001', 'BO001', 2),
('TR001', 'BO002', 1),
('TR002', 'BO002', 1),
('TR003', 'BO003', 1),
('TR004', 'BO004', 2),
('TR005', 'BO002', 1),
('TR005', 'BO005', 1),
('TR005', 'BO009', 1),
('TR006', 'BO002', 1),
('TR006', 'BO006', 1),
('TR007', 'BO005', 1),
('TR007', 'BO007', 1),
('TR008', 'BO002', 2),
('TR008', 'BO008', 1),
('TR009', 'BO001', 2),
('TR009', 'BO009', 2),
('TR010', 'BO005', 1),
('TR010', 'BO010', 1),
('TR011', 'BO005', 1),
('TR011', 'BO009', 2),
('TR012', 'BO006', 2),
('TR012', 'BO009', 1),
('TR013', 'BO007', 1),
('TR014', 'BO006', 2),
('TR015', 'BO008', 1);

-- --------------------------------------------------------

--
-- Table structure for table `transactionheader`
--

CREATE TABLE `transactionheader` (
  `TransactionID` char(5) NOT NULL,
  `CustomerID` char(5) NOT NULL,
  `StaffID` char(5) NOT NULL,
  `TransactionDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transactionheader`
--

INSERT INTO `transactionheader` (`TransactionID`, `CustomerID`, `StaffID`, `TransactionDate`) VALUES
('TR001', 'CU001', 'ST001', '2020-05-09'),
('TR002', 'CU002', 'ST001', '2020-06-09'),
('TR003', 'CU004', 'ST002', '2020-05-19'),
('TR004', 'CU005', 'ST005', '2020-05-29'),
('TR005', 'CU003', 'ST003', '2020-11-08'),
('TR006', 'CU004', 'ST003', '2020-12-28'),
('TR007', 'CU005', 'ST004', '2020-10-08'),
('TR008', 'CU006', 'ST005', '2020-09-15'),
('TR009', 'CU007', 'ST006', '2020-10-27'),
('TR010', 'CU008', 'ST006', '2020-05-29'),
('TR011', 'CU009', 'ST009', '2020-05-13'),
('TR012', 'CU010', 'ST010', '2020-04-04'),
('TR013', 'CU005', 'ST006', '2020-11-10'),
('TR014', 'CU001', 'ST005', '2020-07-08'),
('TR015', 'CU010', 'ST001', '2020-03-05');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `msbook`
--
ALTER TABLE `msbook`
  ADD PRIMARY KEY (`BookID`);

--
-- Indexes for table `mscustomer`
--
ALTER TABLE `mscustomer`
  ADD PRIMARY KEY (`CustomerID`);

--
-- Indexes for table `msstaff`
--
ALTER TABLE `msstaff`
  ADD PRIMARY KEY (`StaffID`);

--
-- Indexes for table `transactiondetail`
--
ALTER TABLE `transactiondetail`
  ADD PRIMARY KEY (`TransactionID`,`BookID`),
  ADD KEY `BookID` (`BookID`);

--
-- Indexes for table `transactionheader`
--
ALTER TABLE `transactionheader`
  ADD PRIMARY KEY (`TransactionID`),
  ADD KEY `StaffID` (`StaffID`),
  ADD KEY `CustomerID` (`CustomerID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `transactiondetail`
--
ALTER TABLE `transactiondetail`
  ADD CONSTRAINT `transactiondetail_ibfk_1` FOREIGN KEY (`BookID`) REFERENCES `msbook` (`BookID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `transactionheader`
--
ALTER TABLE `transactionheader`
  ADD CONSTRAINT `transactionheader_ibfk_1` FOREIGN KEY (`StaffID`) REFERENCES `msstaff` (`StaffID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `transactionheader_ibfk_2` FOREIGN KEY (`CustomerID`) REFERENCES `mscustomer` (`CustomerID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
