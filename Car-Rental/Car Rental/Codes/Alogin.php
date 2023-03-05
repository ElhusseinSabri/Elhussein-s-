<?php session_start();

// initializing variables
$admin_id = "";
$name = "";
$email = "";
$errors = array(); 

// connect to the database
$db = mysqli_connect('localhost', 'root', '', 'Car_Rental_System');
if (isset($_POST['login_user'])) {
	$name = mysqli_real_escape_string($db, $_POST['name']);
	$password = mysqli_real_escape_string($db, $_POST['password']);
  
	if (empty($name)) {
		array_push($errors, "A name is required");
	}
	if (empty($password)) {
		array_push($errors, "Password is required");
	}
  
	if (count($errors) == 0) {
		$password = md5($password);
		$query = "SELECT * FROM admin WHERE name='$name' AND password='$password'";
		$results = mysqli_query($db, $query);
		if (mysqli_num_rows($results) == 1) {
		  $_SESSION['name'] = $name;
		  $_SESSION['success'] = "You are now logged in";
		  header('location: index.php');
		}else {
			array_push($errors, "Wrong username/password ");
		}
	}
  }
   ?>
<!DOCTYPE html>
<html>
<head>
  <title>Registration </title>
  <link rel="stylesheet" type="text/css" href="style.css">
  <style>
	     body {
          margin: 100px;
          padding: 100px;
          font-size: 120%;
          background-image: url("log.jpg");
          background-repeat: no-repeat;
          background-size: 1550px 950px;
  }
        
  </style>
</head>
<body>
  <div class="header">
  	<h2>Login</h2>
  </div>
	 
  <form method="post" action="Alogin.php">
  	<?php  if (count($errors) > 0) : ?>
  <div class="error">
  	<?php foreach ($errors as $error) : ?>
  	  <p><?php echo $error ?></p>
  	<?php endforeach ?>
  </div>
<?php  endif ?>
  	<div class="input-group">
  		<label>Username</label>
  		<input type="text" name="name" >
  	</div>
  	<div class="input-group">
  		<label>Password</label>
  		<input type="password" name="password">
  	</div>
  	<div class="input-group">
  		<button type="submit" class="btn" name="login_user">Login</button>
  	</div>
  	<p>
  		  <a href="home.html">Home</a>
  	</p>
	
  </form>
  
</body>
</html>