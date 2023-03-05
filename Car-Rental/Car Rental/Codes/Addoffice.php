<?php session_start();

$office_id = "";
$country = "";
$city = "";
$errors = array(); 

$db = mysqli_connect('localhost', 'root', '', 'Car_Rental_System');


if (isset($_POST['add_office'])) {
  // receive all input values from the form
  $office_id = mysqli_real_escape_string($db, $_POST['office_id']);
  $country = mysqli_real_escape_string($db, $_POST['country']);
  $city = mysqli_real_escape_string($db, $_POST['city']);
  

  
  if (empty($office_id)) { array_push($errors, "office id is required"); }
  if (empty($country)) { array_push($errors, "country is required"); }
  if (empty($city)) { array_push($errors, "city name is required"); }

  

  // first check the database to make sure 
  // a user does not already exist with the same username and/or email
  $check_query = "SELECT * FROM office WHERE office_id='$office_id'";
  $result = mysqli_query($db, $check_query);
  $r = mysqli_fetch_assoc($result);
  
  if ($r) { // if user exists
    if ($r['office_id'] === $office_id) {
      array_push($errors, "office_id already exists");
    } 

    if ($r['city'] === $city) {
      array_push($errors, "an office already exists in this city");
    }

    
  }

  // Finally, register user if there are no errors in the form
  if (count($errors) == 0) {
  	
      
  	$query = "INSERT INTO office (office_id, city, country) 
  			  VALUES('$office_id', '$city', '$country')";
  	mysqli_query($db, $query);
  	//$_SESSION['name'] = $name;
  	//$_SESSION['success'] = "Office Saved";
  	//header('location: Addoffice.php');
  }
}
 ?> 
<!DOCTYPE html>
<html>
<head>
  <title>Registration system PHP and MySQL</title>
  <link rel="stylesheet" type="text/css" href="style.css">
  <style>
	     body {
          margin: 100px;
          padding: 100px;
          font-size: 120%;
          background-image: url("pag.png");
          background-repeat: no-repeat;
          background-size: 1550px 1050px;
  }
        
  </style>
  
</head>
<body>
  <div class="header">
  	<h2>Add New Office</h2>
  </div>
	
  <form id="form" method="post" action="Addoffice.php">
  <?php if (count($errors) > 0) : ?>
  <div class="error">
    <?php foreach ($errors as $error) : ?>
      <p><?php echo $error ?></p>
    <?php endforeach ?>
  </div>
<?php  endif ?>
    <div class="input-group">
  	  <label>Office id</label>
  	  <input type="text" id="office_id" name="office_id" value="">
  	</div>
  	<div class="input-group">
  	  <label>City</label>
  	  <input type="text" id="city" name="city" value="">
  	</div>
  	<div class="input-group">
  	  <label>Country</label>
  	  <input type="country" id="country" name="country" value="">
  	</div>  
  	
  	<div class="input-group">
  	  <button type="submit" class="btn" name="add_office">Add Office</button>
      <a href="home.html">Home</a>
  	</div>
  	  <p>
        <a href="index.php">Admin Page</a>
    </p>
    
        

  </form>
</body>
</html>