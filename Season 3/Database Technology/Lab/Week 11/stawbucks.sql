-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 06, 2022 at 12:50 PM
-- Server version: 10.4.25-MariaDB
-- PHP Version: 7.4.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `stawbucks`
--

-- --------------------------------------------------------

--
-- Table structure for table `baristas`
--

CREATE TABLE `baristas` (
  `barista_id` char(5) NOT NULL,
  `barista_name` varchar(50) NOT NULL,
  `barista_gender` varchar(6) NOT NULL,
  `barista_address` varchar(50) NOT NULL,
  `barista_salary` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `baristas`
--

INSERT INTO `baristas` (`barista_id`, `barista_name`, `barista_gender`, `barista_address`, `barista_salary`) VALUES
('BR001', 'Brooklyn Welsh', 'Male', '27 Spilman Street', 5421000),
('BR002', 'Giovanni Carney', 'Male', '34 Greyfriars Road', 3800000),
('BR003', 'Krystian Ireland', 'Male', '74 Dunmow Road', 2750000),
('BR004', 'Rikki Rich', 'Male', '61 Souterhead Road', 15480000),
('BR005', 'Abid Quintana', 'Male', '48 Greyfriars Road', 6200000),
('BR006', 'Jordon Wharton', 'Male', '80 Sandyhill Road', 4710000),
('BR007', 'Donald Downs', 'Male', '3 Prospect Hill', 5650000),
('BR008', 'Annabelle Nicholson', 'Female', '78 Long Street', 4900000),
('BR009', 'Charleigh Bravo', 'Female', '67 Park End Street', 3750000),
('BR010', 'Renesmee Juarez', 'Female', '43 Iffley Road', 7100000),
('BR011', 'Acacia Walsh', 'Female', '31 Guildford Road', 4120000),
('BR012', 'Sabrina Ford', 'Female', '32 Bootham Crescent', 3210000),
('BR013', 'Linda Jefferson', 'Female', '80 St Maurices Road', 6600000),
('BR014', 'Remy Carrillo', 'Female', '31 Front Street', 8150000),
('BR015', 'Romana Ridley', 'Female', '21 Leicester Road', 9480000);

-- --------------------------------------------------------

--
-- Table structure for table `coffees`
--

CREATE TABLE `coffees` (
  `coffee_id` char(5) NOT NULL,
  `coffee_name` varchar(50) NOT NULL,
  `coffee_price` int(10) NOT NULL,
  `coffee_type_id` char(5) NOT NULL
) ;

--
-- Dumping data for table `coffees`
--

INSERT INTO `coffees` (`coffee_id`, `coffee_name`, `coffee_price`, `coffee_type_id`) VALUES
('CO001', 'Salted Caramel Cream Cold Brew', 62999, 'CT007'),
('CO002', 'Java Chip Cappuccino', 37000, 'CT005'),
('CO003', 'Vanilla Bean Crème Cappuccino', 42999, 'CT005'),
('CO004', 'Caramel Macchiato', 54999, 'CT004'),
('CO005', 'Chocolate Cream Irish Coffee', 38499, 'CT008'),
('CO006', 'Iced Starbucks Blonde Vanilla Latte', 37500, 'CT009'),
('CO007', 'Caffè Americano', 28500, 'CT003'),
('CO008', 'Dark Roast Coffee', 24900, 'CT001'),
('CO009', 'Honey Almondmilk Flat White', 31299, 'CT006'),
('CO010', 'Iced Chocolate Almondmilk Shaken Espresso', 33799, 'CT002'),
('CO011', 'Apple Crisp Oatmilk Macchiato', 53999, 'CT004'),
('CO012', 'Matcha Tea Latte', 23999, 'CT009'),
('CO013', 'Cinnamon Dolce Affogato', 67999, 'CT007'),
('CO014', 'Hot Chocolate', 48999, 'CT010'),
('CO015', 'Pumpkin Spice Latte', 56500, 'CT009');

-- --------------------------------------------------------

--
-- Table structure for table `coffee_sizes`
--

CREATE TABLE `coffee_sizes` (
  `coffee_size_id` char(5) NOT NULL,
  `coffee_size_name` varchar(30) NOT NULL,
  `coffee_size_quantity` int(10) NOT NULL
) ;

--
-- Dumping data for table `coffee_sizes`
--

INSERT INTO `coffee_sizes` (`coffee_size_id`, `coffee_size_name`, `coffee_size_quantity`) VALUES
('CS001', 'Tall', 355),
('CS002', 'Grande', 473),
('CS003', 'Venti', 591),
('CS004', 'Short', 236);

-- --------------------------------------------------------

--
-- Table structure for table `coffee_types`
--

CREATE TABLE `coffee_types` (
  `coffee_type_id` char(5) NOT NULL,
  `coffee_type_name` varchar(50) NOT NULL,
  `coffee_strength` int(10) NOT NULL
) ;

--
-- Dumping data for table `coffee_types`
--

INSERT INTO `coffee_types` (`coffee_type_id`, `coffee_type_name`, `coffee_strength`) VALUES
('CT001', 'Doppio', 10),
('CT002', 'Espresso', 9),
('CT003', 'Americano', 8),
('CT004', 'Macchiato', 7),
('CT005', 'Cappucino', 6),
('CT006', 'Flat White', 5),
('CT007', 'Affogato', 4),
('CT008', 'Irish Coffee', 3),
('CT009', 'Latte', 2),
('CT010', 'Decaf', 1);

-- --------------------------------------------------------

--
-- Table structure for table `customers`
--

CREATE TABLE `customers` (
  `customer_id` char(5) NOT NULL,
  `customer_name` varchar(50) NOT NULL,
  `customer_gender` varchar(6) NOT NULL,
  `customer_address` varchar(50) NOT NULL,
  `is_member` varchar(3) NOT NULL
) ;

--
-- Dumping data for table `customers`
--

INSERT INTO `customers` (`customer_id`, `customer_name`, `customer_gender`, `customer_address`, `is_member`) VALUES
('CU001', 'Billy Ratliff', 'Female', '9538 Victoria Road', 'Yes'),
('CU002', 'Karishma Driscoll', 'Female', '4 Queen Street', 'Yes'),
('CU003', 'Armani Dickens', 'Female', '12 Main Street', 'No'),
('CU004', 'Eren Dawson', 'Female', '83 Mill Road', 'Yes'),
('CU005', 'Sumaiyah Barclay', 'Female', '9 London Road', 'No'),
('CU006', 'Tyron Hills', 'Male', '74 Main Road', 'No'),
('CU007', 'Arnold Gray', 'Male', '9815 Queens Road', 'No'),
('CU008', 'Matt Sweeney', 'Male', '80 Windsor Road', 'Yes'),
('CU009', 'Varun Levy', 'Male', '3 West Street', 'Yes'),
('CU010', 'Tyler-Jay Newton', 'Male', '20 York Road', 'No');

-- --------------------------------------------------------

--
-- Table structure for table `transaction_details`
--

CREATE TABLE `transaction_details` (
  `transaction_id` char(5) NOT NULL,
  `coffee_id` char(5) NOT NULL,
  `coffee_size_id` char(5) NOT NULL,
  `quantity` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction_details`
--

INSERT INTO `transaction_details` (`transaction_id`, `coffee_id`, `coffee_size_id`, `quantity`) VALUES
('TR001', 'CO001', 'CS001', 4),
('TR001', 'CO004', 'CS004', 3),
('TR002', 'CO015', 'CS003', 1),
('TR003', 'CO009', 'CS003', 2),
('TR004', 'CO005', 'CS002', 5),
('TR004', 'CO007', 'CS004', 2),
('TR005', 'CO005', 'CS001', 1),
('TR006', 'CO008', 'CS002', 4),
('TR007', 'CO009', 'CS001', 3),
('TR008', 'CO006', 'CS003', 7),
('TR008', 'CO011', 'CS004', 8),
('TR009', 'CO013', 'CS001', 5),
('TR010', 'CO010', 'CS004', 3),
('TR011', 'CO005', 'CS002', 1),
('TR012', 'CO006', 'CS001', 2),
('TR013', 'CO008', 'CS003', 6),
('TR014', 'CO006', 'CS003', 4),
('TR015', 'CO013', 'CS004', 3),
('TR016', 'CO001', 'CS001', 1),
('TR017', 'CO002', 'CS002', 2),
('TR017', 'CO008', 'CS001', 7),
('TR017', 'CO012', 'CS001', 8),
('TR018', 'CO007', 'CS001', 1),
('TR018', 'CO011', 'CS002', 9),
('TR018', 'CO015', 'CS003', 2),
('TR019', 'CO002', 'CS001', 5),
('TR019', 'CO003', 'CS004', 1),
('TR020', 'CO001', 'CS003', 2),
('TR020', 'CO008', 'CS004', 2),
('TR020', 'CO015', 'CS002', 2);

-- --------------------------------------------------------

--
-- Table structure for table `transaction_headers`
--

CREATE TABLE `transaction_headers` (
  `transaction_id` char(5) NOT NULL,
  `customer_id` char(5) DEFAULT NULL,
  `barista_id` char(5) DEFAULT NULL,
  `transaction_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction_headers`
--

INSERT INTO `transaction_headers` (`transaction_id`, `customer_id`, `barista_id`, `transaction_date`) VALUES
('TR001', 'CU003', 'BR015', '2021-12-01'),
('TR002', 'CU005', 'BR011', '2021-12-03'),
('TR003', 'CU001', 'BR005', '2021-12-05'),
('TR004', 'CU006', 'BR007', '2021-12-06'),
('TR005', 'CU007', 'BR003', '2021-12-08'),
('TR006', 'CU007', 'BR006', '2021-12-10'),
('TR007', 'CU002', 'BR003', '2021-12-14'),
('TR008', 'CU009', 'BR008', '2021-12-15'),
('TR009', 'CU010', 'BR009', '2021-12-18'),
('TR010', 'CU004', 'BR007', '2021-12-20'),
('TR011', 'CU005', 'BR012', '2021-12-21'),
('TR012', 'CU001', 'BR010', '2021-12-23'),
('TR013', 'CU003', 'BR001', '2021-12-23'),
('TR014', 'CU008', 'BR002', '2021-12-24'),
('TR015', 'CU008', 'BR005', '2021-12-24'),
('TR016', 'CU006', 'BR014', '2021-12-25'),
('TR017', 'CU002', 'BR008', '2021-12-25'),
('TR018', 'CU009', 'BR005', '2021-12-25'),
('TR019', 'CU010', 'BR006', '2021-12-26'),
('TR020', 'CU010', 'BR007', '2021-12-26');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `baristas`
--
ALTER TABLE `baristas`
  ADD PRIMARY KEY (`barista_id`);

--
-- Indexes for table `coffees`
--
ALTER TABLE `coffees`
  ADD PRIMARY KEY (`coffee_id`),
  ADD KEY `coffee_type_id` (`coffee_type_id`);

--
-- Indexes for table `coffee_sizes`
--
ALTER TABLE `coffee_sizes`
  ADD PRIMARY KEY (`coffee_size_id`);

--
-- Indexes for table `coffee_types`
--
ALTER TABLE `coffee_types`
  ADD PRIMARY KEY (`coffee_type_id`);

--
-- Indexes for table `customers`
--
ALTER TABLE `customers`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indexes for table `transaction_details`
--
ALTER TABLE `transaction_details`
  ADD PRIMARY KEY (`transaction_id`,`coffee_id`,`coffee_size_id`),
  ADD KEY `coffee_id` (`coffee_id`),
  ADD KEY `coffee_size_id` (`coffee_size_id`);

--
-- Indexes for table `transaction_headers`
--
ALTER TABLE `transaction_headers`
  ADD PRIMARY KEY (`transaction_id`),
  ADD KEY `customer_id` (`customer_id`),
  ADD KEY `barista_id` (`barista_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `coffees`
--
ALTER TABLE `coffees`
  ADD CONSTRAINT `coffees_ibfk_1` FOREIGN KEY (`coffee_type_id`) REFERENCES `coffee_types` (`coffee_type_id`) ON UPDATE CASCADE ON DELETE CASCADE;

--
-- Constraints for table `transaction_details`
--
ALTER TABLE `transaction_details`
  ADD CONSTRAINT `transaction_details_ibfk_1` FOREIGN KEY (`coffee_id`) REFERENCES `coffees` (`coffee_id`) ON UPDATE CASCADE ON DELETE CASCADE,
  ADD CONSTRAINT `transaction_details_ibfk_2` FOREIGN KEY (`coffee_size_id`) REFERENCES `coffee_sizes` (`coffee_size_id`) ON UPDATE CASCADE ON DELETE CASCADE;

--
-- Constraints for table `transaction_headers`
--
ALTER TABLE `transaction_headers`
  ADD CONSTRAINT `transaction_headers_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customers` (`customer_id`) ON UPDATE CASCADE ON DELETE CASCADE,
  ADD CONSTRAINT `transaction_headers_ibfk_2` FOREIGN KEY (`barista_id`) REFERENCES `baristas` (`barista_id`) ON UPDATE CASCADE ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
