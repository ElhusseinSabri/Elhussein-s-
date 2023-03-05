<?php session_start();

// initializing variables
$admin_id = "";
$name = "";
$email = "";
$errors = array(); 

// connect to the database
$db = mysqli_connect('localhost', 'root', '', 'Car_Rental_System');

// REGISTER USER
if (isset($_POST['reg_user'])) {
  // receive all input values from the form
  $admin_id = mysqli_real_escape_string($db, $_POST['admin_id']);
  $name = mysqli_real_escape_string($db, $_POST['name']);
  $email = mysqli_real_escape_string($db, $_POST['email']);
  $password_1 = mysqli_real_escape_string($db, $_POST['password_1']);
  $password_2 = mysqli_real_escape_string($db, $_POST['password_2']);

  // form validation: ensure that the form is correctly filled ...
  // by adding (array_push()) corresponding error unto $errors array
  if (empty($admin_id)) { array_push($errors, "admin_id number is required"); }
  if (empty($name)) { array_push($errors, "A name is required"); }
  if (empty($email)) { array_push($errors, "Email is required"); }
  if (empty($password_1)) { array_push($errors, "Password is required"); }
  if ($password_1 != $password_2) {
	array_push($errors, "The two passwords do not match");
  }

  // first check the database to make sure 
  // a user does not already exist with the same username and/or email
  $admin_check_query = "SELECT * FROM admin WHERE name='$name' OR admin_id='$admin_id' OR email='$email' LIMIT 1";
  $result = mysqli_query($db, $admin_check_query);
  $admin = mysqli_fetch_assoc($result);
  
  if ($admin) { // if user exists
    if ($admin['name'] === $name) {
      array_push($errors, "Username already exists");
    }

    if ($admin['email'] === $email) {
      array_push($errors, "email already exists");
    }

    if ($admin['admin_id'] === $admin_id) {
        array_push($errors, "admin_id already exists");
    }

  }

  // Finally, register user if there are no errors in the form
  if (count($errors) == 0) {
  	$password = md5($password_1);//encrypt the password before saving in the database

  	$query = "INSERT INTO admin (admin_id, name, email, password) 
  			  VALUES('$admin_id', '$name', '$email', '$password')";
  	mysqli_query($db, $query);
  	$_SESSION['name'] = $name;
  	$_SESSION['success'] = "You are now logged in";
  	header('location: Asignup.php');
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
          background-image: url("log.jpg");
          background-repeat: no-repeat;
          background-size: 1550px 1050px;
  }
        
  </style>
  
</head>
<body>
  <div class="header">
  	<h2>Admin Register</h2>
  </div>
	
  <form id="form" method="post" action="Asignup.php">
  	<?php if (count($errors) > 0) : ?>
  <div class="error">
  	<?php foreach ($errors as $error) : ?>
  	  <p><?php echo $error ?></p>
  	<?php endforeach ?>
  </div>
<?php  endif ?>
    
    <div class="input-group">
  	  <label>Admin_id</label>
  	  <input type="admin_id" id="admin_id" name="admin_id" value="<?php echo $admin_id; ?>">
  	</div>
  	<div class="input-group">
  	  <label>Username</label>
  	  <input type="text" id="name" name="name" value="<?php echo $name; ?>">
  	</div>
  	<div class="input-group">
  	  <label>Email</label>
  	  <input type="email" id="email" name="email" value="<?php echo $email; ?>">
  	</div>  
  	<div class="input-group">
  	  <label>Password</label>
  	  <input type="password" id="password_1" name="password_1">
        </div>
  	<div class="input-group">
  	  <label>Confirm password</label>
  	  <input type="password" id="password_2" name="password_2">
  	</div>
  	<div class="input-group">
  	  <button type="submit" class="btn" name="reg_user">Register</button>
  	</div>
  	<p>
  		Already an admin? <a href="Alogin.php">Sign in</a>    <a href="home.html">Home</a>
  	</p>
  </form>
</body>
</html>