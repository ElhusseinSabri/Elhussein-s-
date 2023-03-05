<?php session_start();

// initializing variables
$plate_id = "";
$carstatus = "";
$errors = array(); 
$resdate1="";
$resdate2="";
$i=1;

// connect to the database
$db = mysqli_connect('localhost', 'root', '', 'Car_Rental_System');
if (isset($_POST['change_carstatus'])) {
	if(isset($_POST['carstatus'])){
	$plate_id = mysqli_real_escape_string($db, $_POST['plate_id']);
	$carstatus = mysqli_real_escape_string($db, $_POST['carstatus']);
	$resdate1 = mysqli_real_escape_string($db, $_POST['resdate1']);
	$resdate2 = mysqli_real_escape_string($db, $_POST['resdate2']);
}
  
	if (empty($plate_id)) {
		array_push($errors, "A plate_id is required");
	}
	if (empty($carstatus)) {
		array_push($errors, "carstatus is required");
	}
  
	if (count($errors) == 0) {
		
		$query = "SELECT * FROM car WHERE plate_id='$plate_id' ";
		$results = mysqli_query($db, $query);
		if (mysqli_num_rows($results) >= 1) {
		 // $_SESSION['name'] = $name;
		  //$_SESSION['success'] = "You are now logged in";
		  //header('location: Cindex.php');

		  	$query = "INSERT INTO car_status (plate_id, carstatus,day) 
  			  VALUES('$plate_id', '$carstatus','$resdate1')";

  			  $query2 = "INSERT INTO car_status (plate_id, carstatus,day) 
  			  VALUES('$plate_id', '$carstatus','$resdate2')";

		     $results = mysqli_query($db, $query);
		     $results2 = mysqli_query($db, $query2);
		     $query3="INSERT INTO car_status (plate_id, carstatus,day) 
  			  VALUES('$plate_id', '$carstatus',DATE_ADD('$resdate1', INTERVAL '$i' DAY))";
		      $results3=mysqli_query($db,$query3);
		  while($results3){
		  	$i++;
		  	 $query3="INSERT INTO car_status (plate_id, carstatus,day) 
  			  VALUES('$plate_id', '$carstatus',DATE_ADD('$resdate1', INTERVAL '$i' DAY))";
		  	
		  	try{
		  		$results3=mysqli_query($db,$query3);
		  	}
		  	catch(Exception $e){
		  	
		  		break;
		  	}
		  	
		  }

		}else {
			array_push($errors, "Wrong plate_id ");
		}
	}
  }
   ?>
<!DOCTYPE html>
<html>
<head>
  <title>Change car status</title>


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
  	<h2>Change car status</h2>
  </div>
	 
  <form method="post" action="">
  	<?php  if (count($errors) > 0) : ?>
  <div class="error">
  	<?php foreach ($errors as $error) : ?>
  	  <p><?php echo $error ?></p>
  	<?php endforeach ?>
  </div>
<?php  endif ?>
  	<div class="input-group">
  		<label>Plate id:</label>
  		<input type="text" name="plate_id" >
  	</div>
  	
  		
  		<div class="input-group-radio">
<label for="Active">Active</label>
<input type="radio" class="rb" id="Active" name="carstatus" value="Active">
<label for="Rented">Rented</label>
<input type="radio" class="rb" id="Rented" name="carstatus" value="Rented">
<label for="out_of_service">Out of service</label> 
<input type="radio"  class="rb"id="out_of_service" name="carstatus" value="out of service">
  

                      <div class="date"> 
                      	    <label for="resdate1">From</label>
                            <input type="date" name="resdate1" id="resdate1" value="">
                            <label for="resdate2">To</label>
                            <input type="date" name="resdate2" id="resdate2" value="">
                          </div>

  	</div>
  	<div class="input-group">
  		<button type="submit" class="btn" name="change_carstatus">Change status</button>
  	</div>
  	<p>
  		  <a href="home.html">Home</a>
  	</p>
  	<p>
  		  <a href="index.php">Admin Page</a>
  	</p>
	
  </form>
  
</body>
</html>