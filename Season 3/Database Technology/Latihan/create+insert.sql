-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 04, 2022 at 06:38 AM
-- Server version: 10.4.19-MariaDB
-- PHP Version: 8.0.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `onlineshop`
--

-- --------------------------------------------------------

--
-- Table structure for table `customers`
--

CREATE TABLE `customers` (
  `customer_id` char(5) NOT NULL CHECK (`customer_id` regexp 'CU[0-9][0-9][0-9]'),
  `customer_name` varchar(255) NOT NULL,
  `customer_gender` varchar(255) NOT NULL CHECK (`customer_gender` in ('Male','Female')),
  `customer_address` varchar(255) NOT NULL,
  `customer_dob` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `customers`
--

INSERT INTO `customers` (`customer_id`, `customer_name`, `customer_gender`, `customer_address`, `customer_dob`) VALUES
('CU001', 'Ani Sukaini', 'Male', 'Jl. Mawar', '1999-10-11'),
('CU002', 'Budi Budiman', 'Male', 'Jl. Aggrek', '1990-08-03'),
('CU003', 'Caca Cacamen', 'Female', 'Jl. Matahari', '2003-01-22'),
('CU004', 'Rehan Baik', 'Male', 'Jl. Bulan', '2007-04-20'),
('CU005', 'Egi Sugaga', 'Female', 'Jl. Bintang', '2001-05-12'),
('CU006', 'Figo Haaland', 'Male', 'Jl. Angkasa', '2010-12-10');

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
  `product_id` char(5) NOT NULL CHECK (`product_id` regexp 'PR[0-9][0-9][0-9]'),
  `product_name` varchar(255) NOT NULL,
  `product_price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`product_id`, `product_name`, `product_price`) VALUES
('PR001', 'Laptop ASIS GOR G17', 24750000),
('PR002', 'Keyboard Keychrin K6 Pro', 1930500),
('PR003', 'Laptop Lenovi YOGA', 18810000),
('PR004', 'Mouse HP A133', 64350),
('PR005', 'Keyboard Rexis DAXO', 965250),
('PR006', 'Laptop MSU Raider GF66 ', 64350000),
('PR007', 'Phone Simsung S30', 21285000),
('PR008', 'Headset StoleSeries', 1217700),
('PR009', 'Laptop Ecar XA123', 14850000);

-- --------------------------------------------------------

--
-- Table structure for table `staffs`
--

CREATE TABLE `staffs` (
  `staff_id` char(5) NOT NULL CHECK (`staff_id` regexp 'ST[0-9][0-9][0-9]'),
  `staff_name` varchar(255) NOT NULL,
  `staff_gender` varchar(255) NOT NULL CHECK (`staff_gender` in ('Male','Female')),
  `staff_address` varchar(255) NOT NULL,
  `staff_dob` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `staffs`
--

INSERT INTO `staffs` (`staff_id`, `staff_name`, `staff_gender`, `staff_address`, `staff_dob`) VALUES
('ST001', 'Andhika Pertama', 'Male', 'Jl. Mawar', '1968-12-12'),
('ST002', 'Boy Millia', 'Male', 'Jl. Aggrek', '1956-01-12'),
('ST003', 'Cristiano Messi', 'Male', 'Jl. Matahari', '2002-08-10'),
('ST004', 'David Ben', 'Male', 'Jl. Bulan', '2003-06-12'),
('ST005', 'Erling Holand', 'Male', 'Jl. Bintang', '1948-04-16'),
('ST006', 'Filia Yesi', 'Female', 'Jl. Angkasa', '1998-10-12');

-- --------------------------------------------------------

--
-- Table structure for table `transaction_detail`
--

CREATE TABLE `transaction_detail` (
  `transaction_id` char(5) NOT NULL,
  `product_id` char(5) NOT NULL,
  `quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction_detail`
--

INSERT INTO `transaction_detail` (`transaction_id`, `product_id`, `quantity`) VALUES
('TR001', 'PR001', 1),
('TR001', 'PR003', 2),
('TR001', 'PR004', 5),
('TR002', 'PR001', 8),
('TR003', 'PR001', 2),
('TR004', 'PR003', 3),
('TR005', 'PR006', 5),
('TR005', 'PR007', 10),
('TR006', 'PR004', 25),
('TR006', 'PR007', 11),
('TR007', 'PR004', 7),
('TR007', 'PR005', 8),
('TR007', 'PR006', 9),
('TR008', 'PR002', 5),
('TR008', 'PR009', 3),
('TR009', 'PR003', 2),
('TR010', 'PR004', 1);

-- --------------------------------------------------------

--
-- Table structure for table `transaction_header`
--

CREATE TABLE `transaction_header` (
  `transaction_id` char(5) NOT NULL CHECK (`transaction_id` regexp 'TR[0-9][0-9][0-9]'),
  `customer_id` char(5) NOT NULL,
  `staff_id` char(5) NOT NULL,
  `transaction_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction_header`
--

INSERT INTO `transaction_header` (`transaction_id`, `customer_id`, `staff_id`, `transaction_date`) VALUES
('TR001', 'CU001', 'ST001', '2022-06-03'),
('TR002', 'CU002', 'ST003', '2022-05-03'),
('TR003', 'CU003', 'ST004', '2022-06-03'),
('TR004', 'CU002', 'ST002', '2021-11-06'),
('TR005', 'CU006', 'ST005', '2022-06-03'),
('TR006', 'CU005', 'ST006', '2021-07-25'),
('TR007', 'CU004', 'ST006', '2022-10-26'),
('TR008', 'CU003', 'ST003', '2022-08-17'),
('TR009', 'CU002', 'ST002', '2022-04-09'),
('TR010', 'CU004', 'ST001', '2021-02-20');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `customers`
--
ALTER TABLE `customers`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`product_id`);

--
-- Indexes for table `staffs`
--
ALTER TABLE `staffs`
  ADD PRIMARY KEY (`staff_id`);

--
-- Indexes for table `transaction_detail`
--
ALTER TABLE `transaction_detail`
  ADD PRIMARY KEY (`transaction_id`,`product_id`),
  ADD KEY `product_id` (`product_id`);

--
-- Indexes for table `transaction_header`
--
ALTER TABLE `transaction_header`
  ADD PRIMARY KEY (`transaction_id`),
  ADD KEY `customer_id` (`customer_id`),
  ADD KEY `staff_id` (`staff_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `transaction_detail`
--
ALTER TABLE `transaction_detail`
  ADD CONSTRAINT `transaction_detail_ibfk_1` FOREIGN KEY (`transaction_id`) REFERENCES `transaction_header` (`transaction_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `transaction_detail_ibfk_2` FOREIGN KEY (`product_id`) REFERENCES `products` (`product_id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `transaction_header`
--
ALTER TABLE `transaction_header`
  ADD CONSTRAINT `transaction_header_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customers` (`customer_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `transaction_header_ibfk_2` FOREIGN KEY (`staff_id`) REFERENCES `staffs` (`staff_id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
