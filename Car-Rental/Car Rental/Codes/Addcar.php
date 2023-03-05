<?php session_start();

$plate_id = "";

$category_name = "";
$office_id = "";
$carstatus = "";
$year = "";
$model = "";
$daily_price="";
$errors = array(); 


$db = mysqli_connect('localhost', 'root', '', 'Car_Rental_System');


if (isset($_POST['add_car'])) {
  // receive all input values from the form
  $model = mysqli_real_escape_string($db, $_POST['model']);
  $plate_id = mysqli_real_escape_string($db, $_POST['plate_id']);
  $category_name = mysqli_real_escape_string($db, $_POST['category_name']);
  $office_id = mysqli_real_escape_string($db, $_POST['office_id']);
  $carstatus = mysqli_real_escape_string($db, $_POST['carstatus']);
  $year = mysqli_real_escape_string($db, $_POST['year']);
    $daily_price = mysqli_real_escape_string($db, $_POST['daily_price']); 
 
  
  if (empty($model)) { array_push($errors, "model is required"); }
  if (empty($plate_id)) { array_push($errors, "plate_id is required"); }
  if (empty($category_name)) { array_push($errors, "category name is required"); }
  if (empty($office_id)) { array_push($errors, "office id is required"); }
  if (empty($carstatus)) { array_push($errors, "car carstatus is required"); }
  if (empty($year)) { array_push($errors, "year of manifacturing is required"); }
  if (empty($daily_price)) { array_push($errors, "daily price is required"); }
   
  

  // first check the database to make sure 
  // a user does not already exist with the same username and/or email
  $check_query = "SELECT * FROM car WHERE plate_id='$plate_id'";
  $result = mysqli_query($db, $check_query);
    
  $r = mysqli_fetch_assoc($result);
  
  if ($r) { // if user exists
    if ($r['plate_id'] === $plate_id) {
      array_push($errors, "plate id already exists");
    } 

    //if ($r['city'] === $city) {
      //array_push($errors, "an office already exists in this city");
    //}

    
  }

  // Finally, register user if there are no errors in the form
  if (count($errors) == 0) {
  	
      
  	$query = "INSERT INTO car (plate_id, model, category_name, office_id,  year,daily_price) 
  			  VALUES('$plate_id', '$model', '$category_name' , '$office_id' ,  '$year','$daily_price')";

    $query2 = "INSERT INTO car_status (plate_id, carstatus) 
          VALUES('$plate_id', '$carstatus')";

          
try{
  $res = mysqli_query($db,$query);
  $ress=mysqli_query($db,$query2);
}
    catch(Exception $e) { 
         array_push($errors,"office id doesn't exist");

         // header('location: Addoffice.php');

    }
 /* if(!$res){
    echo("hello");
    //echo($mysqli->error)
  }*/

  	//mysqli_query($db, $query);
  	//$_SESSION['name'] = $name;
  	//$_SESSION['success'] = "Office Saved";
  //	header('location: Addcar.php');
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
          background-size: 1750px 1250px;
  }
        
  </style>

</head>
<body>
  <div class="header">
  	<h2>Add New Car</h2>
  </div>
	
  <form id="form" method="post" action="Addcar.php">

        <?php if (count($errors) > 0) : ?>
  <div class="error">
  
    <?php foreach ($errors as $error) : ?>
      <p><?php echo $error ?></p>
    <?php endforeach ?>
  </div>
<?php  endif ?>
    <div class="input-group">
  	  <label>plate id:</label>
  	  <input type="text" id="plate_id" name="plate_id" value="" >
  	</div>


  	<div class="input-group">
  	  <label>Model:</label>
  	  <input type="text" id="model" name="model" value="">
  	</div>
  	<div class="input-group-radio" style="text-align: left">
      <p>Please select the car category:</p>
      <input type="radio"  id="category_name" name="category_name" value="Sedan">
      <label for="Sedan">Sedan</label><br>
      <input type="radio" id="category_name" name="category_name" value="Hatchback">
      <label for="Hatchback">Hatchback</label><br>
      <input type="radio" id="category_name" name="category_name" value="4X4">
      <label for="4X4">4X4</label><br>  

      <input type="radio" id="category_name" name="category_name" value="SUV">
      <label for="SUV">SUV</label><br>  
      <input type="radio" id="category_name" name="category_name" value="Convertible">
      <label for="Convertible">Convertible</label><br>  
      <input type="radio" id="category_name" name="category_name" value="Minivan">
      <label for="Minivan">Minivan</label><br>  
      <input type="radio" id="category_name" name="category_name" value="Pickup Truck">
      <label for="Pickup Truck">Pickup Truck</label><br>  
      <input type="radio" id="category_name" name="category_name" value="Sport">
      <label for="Sport">Sport</label><br>  
      
    </div>
    
    <div class="input-group">
      <label>office id:</label>
      <input type="text" id="office_id" name="office_id" value="">
    </div>  
    <div class="input-group">
      <label>Year:</label>
      <input type="text" id="year" name="year" value="">
    </div>  
   <div class="input-group-radio" >
      <label for="Active">Active</label>
      <input type="radio" class="rb"  name="carstatus" value="Active">
      <label for="Rented">Rented</label>
      <input type="radio" class="rb"  name="carstatus" value="Rented">
      <label for="out_of_service">Out of service</label> 
      <input type="radio"  class="rb" name="carstatus" value="out of service">
    </div>
    <div class="input-group">
      <label>Daily price:</label>
      <input type="text" id="daily_price" name="daily_price" value="">
    </div>  
  	
  	<div class="input-group">
  	  <button type="submit" class="btn" name="add_car">Add Car</button>
      <a href="home.html">Home</a>
  	</div>
      <p>
        <a href="index.php">Admin Page</a>
    </p>
  	
  </form>
</body>
</html>