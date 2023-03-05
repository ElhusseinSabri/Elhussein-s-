-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3360
-- Generation Time: Dec 30, 2022 at 11:40 PM
-- Server version: 10.4.25-MariaDB
-- PHP Version: 8.1.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `car_rental_system`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `admin_id` varchar(250) NOT NULL,
  `name` varchar(250) DEFAULT NULL,
  `email` varchar(250) DEFAULT NULL,
  `password` varchar(250) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`admin_id`, `name`, `email`, `password`) VALUES
('12', 'Elhussein Sabri ', 'huss@mail.com', 'c4efd5020cb49b9d3257ffa0fbccc0ae'),
('15', 'huss', 'huss@gmail.com', '935f76f79a4afbcb64aa56804209662e');

-- --------------------------------------------------------

--
-- Table structure for table `car`
--

CREATE TABLE `car` (
  `plate_id` int(11) NOT NULL,
  `model` varchar(255) DEFAULT NULL,
  `office_id` int(11) DEFAULT NULL,
  `category_name` varchar(255) DEFAULT NULL,
  `year` year(4) DEFAULT NULL,
  `daily_price` int(11) NOT NULL,
  `Available` varchar(255) NOT NULL DEFAULT 'yes'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `car`
--

INSERT INTO `car` (`plate_id`, `model`, `office_id`, `category_name`, `year`, `daily_price`, `Available`) VALUES
(33, 's', 12, 'Sedan', 2001, 250, 'no'),
(121, 'i290', 12, 'Sport', 2001, 300, 'no'),
(850, 'ls', 12, 'Sedan', 0000, 500, 'no'),
(1000, 's', 12, 'Sedan', 2010, 450, 'no'),
(88888, 'ks', 11, '4X4', 2012, 1100, 'no'),
(150055, 'i30', 12, '4X4', 2009, 500, 'no');

-- --------------------------------------------------------

--
-- Table structure for table `car_status`
--

CREATE TABLE `car_status` (
  `plate_id` int(11) NOT NULL,
  `day` date NOT NULL,
  `carstatus` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `car_status`
--

INSERT INTO `car_status` (`plate_id`, `day`, `carstatus`) VALUES
(33, '2022-12-01', 'out of service'),
(33, '2022-12-02', 'out of service'),
(33, '2022-12-03', 'out of service'),
(33, '2022-12-04', 'out of service'),
(121, '2022-12-01', 'Active'),
(121, '2022-12-02', 'Active'),
(121, '2022-12-03', 'Active'),
(121, '2022-12-04', 'Active'),
(121, '2022-12-05', 'Active'),
(850, '0000-00-00', 'Active'),
(88888, '0000-00-00', 'Rented'),
(150055, '2022-12-01', 'Active'),
(150055, '2022-12-02', 'Active'),
(150055, '2022-12-03', 'Active'),
(150055, '2022-12-04', 'Active'),
(150055, '2022-12-05', 'Active'),
(150055, '2022-12-06', 'Active'),
(150055, '2022-12-07', 'Active'),
(150055, '2022-12-08', 'Active'),
(150055, '2022-12-09', 'Active'),
(150055, '2022-12-10', 'Active');

-- --------------------------------------------------------

--
-- Table structure for table `category`
--

CREATE TABLE `category` (
  `category_name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `category`
--

INSERT INTO `category` (`category_name`) VALUES
('4X4'),
('Convertible'),
('Hatchback'),
('Minivan'),
('Pickup Truck'),
('Sedan'),
('Sport'),
('SUV');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `customer_id` int(11) NOT NULL,
  `name` varchar(250) DEFAULT NULL,
  `email` varchar(250) DEFAULT NULL,
  `phone` varchar(250) DEFAULT NULL,
  `address` varchar(250) DEFAULT NULL,
  `password` varchar(250) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`customer_id`, `name`, `email`, `phone`, `address`, `password`) VALUES
(1, 'Elhussein Sabri ', 'n@j.com', '01202326369', 'dld', '633de4b0c14ca52ea2432a3c8a5c4c31'),
(2, 'huss', 'kd@hos.com', '0120', 'sld', '935f76f79a4afbcb64aa56804209662e'),
(3, 'hussein', 'jondoe@ds.com', '0120', 'dld', '86a5f0f949bb55dab4626fa9716b16af'),
(4, 'husss', 'jondoe@example.commm', '0120232636', 'dld', '039840883f1746f14d52878745582c99');

-- --------------------------------------------------------

--
-- Table structure for table `dailypayment`
--

CREATE TABLE `dailypayment` (
  `reserve_id` int(11) NOT NULL,
  `payments` int(11) DEFAULT NULL,
  `day` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `dailypayment`
--

INSERT INTO `dailypayment` (`reserve_id`, `payments`, `day`) VALUES
(44, 250, '2022-12-01'),
(44, 250, '2022-12-02'),
(44, 250, '2022-12-03'),
(44, 250, '2022-12-04'),
(44, 250, '2022-12-05'),
(45, 500, '2022-12-04'),
(45, 500, '2022-12-05'),
(45, 500, '2022-12-06'),
(45, 500, '2022-12-07'),
(45, 500, '2022-12-08'),
(46, 300, '2022-12-01'),
(46, 300, '2022-12-02'),
(46, 300, '2022-12-03'),
(46, 300, '2022-12-04'),
(46, 300, '2022-12-05'),
(47, 500, '2022-12-01'),
(47, 500, '2022-12-02'),
(47, 500, '2022-12-03'),
(47, 500, '2022-12-04'),
(47, 500, '2022-12-05'),
(48, 450, '2022-12-01'),
(48, 450, '2022-12-02'),
(48, 450, '2022-12-03'),
(48, 450, '2022-12-04'),
(48, 450, '2022-12-05'),
(49, 1100, '2023-01-01'),
(49, 1100, '2023-01-02'),
(49, 1100, '2023-01-03'),
(49, 1100, '2023-01-04'),
(49, 1100, '2023-01-05');

-- --------------------------------------------------------

--
-- Table structure for table `office`
--

CREATE TABLE `office` (
  `office_id` int(11) NOT NULL,
  `country` varchar(255) NOT NULL,
  `city` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `office`
--

INSERT INTO `office` (`office_id`, `country`, `city`) VALUES
(11, ' egypt', ' damietta'),
(12, 'egypt', 'alexandria'),
(22, 'egypt', ' cairo'),
(212, 'egypt', 'cairo  ');

-- --------------------------------------------------------

--
-- Table structure for table `reservation`
--

CREATE TABLE `reservation` (
  `reserve_id` int(11) NOT NULL,
  `plate_id` int(11) DEFAULT NULL,
  `customer_id` int(11) DEFAULT NULL,
  `pickup_date` date DEFAULT NULL,
  `return_date` date DEFAULT NULL,
  `payment` varchar(255) DEFAULT NULL,
  `reserve_date` date DEFAULT current_timestamp(),
  `total_price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `reservation`
--

INSERT INTO `reservation` (`reserve_id`, `plate_id`, `customer_id`, `pickup_date`, `return_date`, `payment`, `reserve_date`, `total_price`) VALUES
(48, 1000, 2, '2022-12-01', '2022-12-05', 'Check', '2022-12-31', 2250),
(49, 88888, 2, '2023-01-01', '2023-01-05', 'Check', '2022-12-31', 5500);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`admin_id`);

--
-- Indexes for table `car`
--
ALTER TABLE `car`
  ADD PRIMARY KEY (`plate_id`),
  ADD KEY `category_name` (`category_name`),
  ADD KEY `office_id` (`office_id`);

--
-- Indexes for table `car_status`
--
ALTER TABLE `car_status`
  ADD PRIMARY KEY (`plate_id`,`day`);

--
-- Indexes for table `category`
--
ALTER TABLE `category`
  ADD PRIMARY KEY (`category_name`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indexes for table `dailypayment`
--
ALTER TABLE `dailypayment`
  ADD PRIMARY KEY (`reserve_id`,`day`);

--
-- Indexes for table `office`
--
ALTER TABLE `office`
  ADD PRIMARY KEY (`office_id`);

--
-- Indexes for table `reservation`
--
ALTER TABLE `reservation`
  ADD PRIMARY KEY (`reserve_id`),
  ADD KEY `customer_id` (`customer_id`),
  ADD KEY `plate_id` (`plate_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `customer_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `reservation`
--
ALTER TABLE `reservation`
  MODIFY `reserve_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=50;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `car`
--
ALTER TABLE `car`
  ADD CONSTRAINT `car_ibfk_1` FOREIGN KEY (`category_name`) REFERENCES `category` (`category_name`),
  ADD CONSTRAINT `car_ibfk_2` FOREIGN KEY (`office_id`) REFERENCES `office` (`office_id`);

--
-- Constraints for table `car_status`
--
ALTER TABLE `car_status`
  ADD CONSTRAINT `car_status_ibfk_1` FOREIGN KEY (`plate_id`) REFERENCES `car` (`plate_id`);

--
-- Constraints for table `reservation`
--
ALTER TABLE `reservation`
  ADD CONSTRAINT `reservation_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  ADD CONSTRAINT `reservation_ibfk_2` FOREIGN KEY (`plate_id`) REFERENCES `car` (`plate_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
