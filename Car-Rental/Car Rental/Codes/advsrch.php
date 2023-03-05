<?php
$hostname = "localhost";
$database = "car_rental_system";
$username = "root";
$password = "";

$conn = new mysqli($hostname,$username,$password,$database);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
  }
?>