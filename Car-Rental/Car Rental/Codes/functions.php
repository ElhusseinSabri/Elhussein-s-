<?php
require_once('advsrch.php');

function getYear(){
    global $database;
    global $conn;

$sql = "SELECT DISTINCT * FROM car";

if($result = mysqli_query($conn,$sql))
{
if(mysqli_num_rows($result) > 0){
    echo "<select name=\"year\">";
    echo "<option value=\"\">Any year&hellip;</option>\n"; 
    while($row = mysqli_fetch_array($result)){
        echo "<option value='" . $row['year'] . "'>" . $row['year'] . "</option>";
    }
    echo "</select>";
}
}
}

function getCity(){
    global $database;
    global $conn;

$sql = "SELECT DISTINCT * FROM office";

if($result = mysqli_query($conn,$sql))
{
if(mysqli_num_rows($result) > 0){
    echo "<select name=\"city\">";
    echo "<option value=\"\">Any city&hellip;</option>\n"; 
    while($row = mysqli_fetch_array($result)){
        echo "<option value='" . $row['city'] . "'>" . $row['city'] . "</option>";
    }
    echo "</select>";
}
}
}

function getCategory(){
    global $database;
    global $conn;

$sql = "SELECT DISTINCT * FROM car";

if($result = mysqli_query($conn,$sql))
{
if(mysqli_num_rows($result) > 0){
    echo "<select name=\"category_name\">";
    echo "<option value=\"\">Any category&hellip;</option>\n"; 
    while($row = mysqli_fetch_array($result)){
        echo "<option value='" . $row['category_name'] . "'>" . $row['category_name'] . "</option>";
    }
    echo "</select>";
}
}
}



function getCategories(){
    global $database;
    global $conn;

$sql = "SELECT DISTINCT * FROM category";

if($result = mysqli_query($conn,$sql))
{
if(mysqli_num_rows($result) > 0){
 
    echo "<ul class=\"chckbx\">";
    while($row = mysqli_fetch_array($result)){
        echo "<li>";
        echo "<input type=\"checkbox\" name=\"category_name-".$row['category_name']."\"
        id=\"category_name-".$row['category_name']."\" value=\"".$row['category_name']."\" />
        <label for=\"category_name-".$row['category_name']."\">".$row['category_name']."</label>";
        echo "</li>";
    }
    echo "</ul>";
}
}
}

function getStatus(){
    global $database;
    global $conn;

$sql = "SELECT DISTINCT `Status` FROM car";

if($result = mysqli_query($conn,$sql))
{
if(mysqli_num_rows($result) > 0){
    echo "<label for=\"Status-0\">";
    echo "<input type=\"radio\" name=\"Status\" id=\"Status-0\" value=\"0\"/>\nAny</label>";
    while($row = mysqli_fetch_array($result)){
        echo "<label for=\"Status-".$row['Status']."\">";
        echo "<input type=\"radio\" name=\"Status\" 
        id=\"Status-".$row['Status']."\" value=\"".$row['Status']."\"/>\n".$row['Status']."</label>";
    }
}
}
}


 
?>