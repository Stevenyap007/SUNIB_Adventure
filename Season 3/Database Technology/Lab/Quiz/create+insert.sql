-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 25, 2022 at 05:56 AM
-- Server version: 10.4.13-MariaDB
-- PHP Version: 7.4.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `okieva`
--

-- --------------------------------------------------------

--
-- Table structure for table `mscookie`
--

CREATE TABLE `mscookie` (
  `CookieID` char(10) NOT NULL,
  `CookieBaseFlavor` varchar(255) NOT NULL,
  `CookieTopping` varchar(255) NOT NULL,
  `CookiePrice` int(10) NOT NULL
) ;

--
-- Dumping data for table `mscookie`
--

INSERT INTO `mscookie` (`CookieID`, `CookieBaseFlavor`, `CookieTopping`, `CookiePrice`) VALUES
('CO001', 'Chocolate', 'Brownies', 15000),
('CO002', 'Vanilla', 'Cookies', 10000),
('CO003', 'Strawberry', 'Chocolate Sauce', 7500),
('CO004', 'Mango', 'Mango Bits', 15000),
('CO005', 'Durian', 'Sprinkles', 12500),
('CO006', 'Coffee', 'Caramel Sauce', 15000),
('CO007', 'Mint', 'Chocolate Chip', 10000),
('CO008', 'Lemon', 'Orange Sauce', 15000),
('CO009', 'Blueberry', 'Berries', 12500),
('CO010', 'Matcha', 'Mochi', 15000);

-- --------------------------------------------------------

--
-- Table structure for table `mscustomer`
--

CREATE TABLE `mscustomer` (
  `CustomerID` char(10) NOT NULL,
  `CustomerGender` varchar(255) NOT NULL,
  `CustomerName` varchar(255) NOT NULL,
  `CustomerAddress` varchar(255) NOT NULL,
  `CustomerEmail` varchar(255) NOT NULL,
  `CustomerDOB` date NOT NULL
) ;

--
-- Dumping data for table `mscustomer`
--

INSERT INTO `mscustomer` (`CustomerID`, `CustomerGender`, `CustomerName`, `CustomerAddress`, `CustomerEmail`, `CustomerDOB`) VALUES
('CU001', 'Female', 'Holyvia Marcella', '236 West Avenue Street', 'holyvia@email.com', '1999-03-04'),
('CU002', 'Male', 'Gabriel Matthew Mintana', '456 South Street', 'gabriel@email.com', '2000-09-05'),
('CU003', 'Female', 'Gratia Honestha Patiung', '554 Noble Avenue', 'gratia@email.com', '2003-08-05'),
('CU004', 'Male', 'Anthony William Chandra', '841 White Second Street', 'anthony@email.com', '2002-04-05'),
('CU005', 'Male', 'Jeremy Loa', '614 Green Milton Boulevard', 'jeremy@email.com', '2003-05-01'),
('CU006', 'Male', 'Wiryahadi Gunawan', '12 New Street', 'wiryahadi@email.com', '1998-03-18'),
('CU007', 'Male', 'Vito Caris Untariady', '269 Rocky Freeway', 'vito@email.com', '2004-02-25'),
('CU008', 'Male', 'Renaldi Addison', '657 West Second Avenue', 'renaldi@email.com', '2001-01-02'),
('CU009', 'Male', 'Justine Winata Purwoko', '56 North Old Road', 'tintin@email.com', '1999-04-09'),
('CU010', 'Male', 'Jonathan Raine Wiranata', '87 Milton Street', 'holyvia@email.com', '2002-08-15');

-- --------------------------------------------------------

--
-- Table structure for table `msstaff`
--

CREATE TABLE `msstaff` (
  `StaffID` char(10) NOT NULL,
  `StaffName` varchar(255) NOT NULL,
  `StaffGender` varchar(255) NOT NULL,
  `StaffDOB` date NOT NULL,
  `StaffSalary` int(10) NOT NULL
) ;

--
-- Dumping data for table `msstaff`
--

INSERT INTO `msstaff` (`StaffID`, `StaffName`, `StaffGender`, `StaffDOB`, `StaffSalary`) VALUES
('ST001', 'Jordy Wira Arta', 'Male', '1997-12-19', 2000000),
('ST002', 'Chelsey', 'Female', '1996-02-06', 5000000),
('ST003', 'Johevin Blesstowi', 'Male', '1993-03-17', 4000000),
('ST004', 'Jason', 'Male', '1996-08-19', 2750000),
('ST005', 'Cathy Belvanita', 'Female', '1994-01-13', 3500000),
('ST006', 'Budiman Wijaya', 'Male', '1995-08-01', 3750000),
('ST007', 'Tegar Abdullah', 'Male', '1999-11-04', 2500000),
('ST008', 'Karvin Nanda', 'Male', '1995-05-25', 3250000),
('ST009', 'Hady Gustianto', 'Male', '1998-08-13', 2250000),
('ST010', 'Chyntia Angelica', 'Female', '1992-10-11', 4750000);

-- --------------------------------------------------------

--
-- Table structure for table `transactiondetail`
--

CREATE TABLE `transactiondetail` (
  `TransactionID` char(10) NOT NULL,
  `CookieID` char(10) NOT NULL,
  `Quantity` char(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transactiondetail`
--

INSERT INTO `transactiondetail` (`TransactionID`, `CookieID`, `Quantity`) VALUES
('TR001', 'CO002', '1'),
('TR001', 'CO003', '1'),
('TR001', 'CO009', '2'),
('TR002', 'CO002', '2'),
('TR002', 'CO003', '3'),
('TR003', 'CO005', '1'),
('TR004', 'CO006', '2'),
('TR005', 'CO007', '1'),
('TR006', 'CO008', '1'),
('TR007', 'CO008', '1'),
('TR008', 'CO009', '2'),
('TR009', 'CO001', '1'),
('TR010', 'CO002', '2'),
('TR011', 'CO003', '3'),
('TR012', 'CO004', '1'),
('TR012', 'CO005', '1'),
('TR013', 'CO006', '2'),
('TR014', 'CO005', '1'),
('TR014', 'CO006', '2'),
('TR015', 'CO007', '2');

-- --------------------------------------------------------

--
-- Table structure for table `transactionheader`
--

CREATE TABLE `transactionheader` (
  `TransactionID` char(10) NOT NULL,
  `CustomerID` char(10) NOT NULL,
  `StaffID` char(10) NOT NULL,
  `TransactionDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transactionheader`
--

INSERT INTO `transactionheader` (`TransactionID`, `CustomerID`, `StaffID`, `TransactionDate`) VALUES
('TR001', 'CU001', 'ST002', '2021-04-08'),
('TR002', 'CU002', 'ST003', '2021-08-06'),
('TR003', 'CU003', 'ST004', '2021-08-14'),
('TR004', 'CU003', 'ST004', '2021-10-15'),
('TR005', 'CU004', 'ST005', '2021-10-25'),
('TR006', 'CU005', 'ST004', '2022-01-28'),
('TR007', 'CU005', 'ST006', '2022-02-14'),
('TR008', 'CU005', 'ST007', '2022-02-18'),
('TR009', 'CU006', 'ST008', '2022-03-04'),
('TR010', 'CU004', 'ST008', '2022-03-08'),
('TR011', 'CU007', 'ST009', '2022-03-16'),
('TR012', 'CU007', 'ST002', '2022-04-08'),
('TR013', 'CU010', 'ST003', '2022-06-11'),
('TR014', 'CU009', 'ST005', '2022-06-15'),
('TR015', 'CU010', 'ST004', '2022-07-01');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `mscookie`
--
ALTER TABLE `mscookie`
  ADD PRIMARY KEY (`CookieID`);

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
  ADD PRIMARY KEY (`TransactionID`,`CookieID`),
  ADD KEY `detail_cookie_id_foreign` (`CookieID`);

--
-- Indexes for table `transactionheader`
--
ALTER TABLE `transactionheader`
  ADD PRIMARY KEY (`TransactionID`),
  ADD KEY `transaction_customer_id_foreign` (`CustomerID`),
  ADD KEY `transaction_staff_id_foreign` (`StaffID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `transactiondetail`
--
ALTER TABLE `transactiondetail`
  ADD CONSTRAINT `detail_cookie_id_foreign` FOREIGN KEY (`CookieID`) REFERENCES `mscookie` (`CookieID`),
  ADD CONSTRAINT `detail_transaction_id_foreign` FOREIGN KEY (`TransactionID`) REFERENCES `transactionheader` (`TransactionID`);

--
-- Constraints for table `transactionheader`
--
ALTER TABLE `transactionheader`
  ADD CONSTRAINT `transaction_customer_id_foreign` FOREIGN KEY (`CustomerID`) REFERENCES `mscustomer` (`CustomerID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `transaction_staff_id_foreign` FOREIGN KEY (`StaffID`) REFERENCES `msstaff` (`StaffID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
