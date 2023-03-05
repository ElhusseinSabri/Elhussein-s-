<?php session_start();

// initializing variables
$name = "";
$email = "";
$phone = "";
$address="";
$errors = array(); 

// connect to the database
$db = mysqli_connect('localhost', 'root', '', 'Car_Rental_System');

// REGISTER USER
if (isset($_POST['reg_user'])) {
  // receive all input values from the form
  $name = mysqli_real_escape_string($db, $_POST['name']);
  $email = mysqli_real_escape_string($db, $_POST['email']);
  $phone = mysqli_real_escape_string($db, $_POST['phone']);
  $address = mysqli_real_escape_string($db, $_POST['address']);
  $password_1 = mysqli_real_escape_string($db, $_POST['password_1']);
  $password_2 = mysqli_real_escape_string($db, $_POST['password_2']);

  // form validation: ensure that the form is correctly filled ...
  // by adding (array_push()) corresponding error unto $errors array
  if (empty($name)) { array_push($errors, "A name is required"); }
  if (empty($email)) { array_push($errors, "Email is required"); }
  if (empty($phone)) { array_push($errors, "Phone number is required"); }
  if (empty($address)) { array_push($errors, "An address is required"); }
  if (empty($password_1)) { array_push($errors, "Password is required"); }
  if ($password_1 != $password_2) {
	array_push($errors, "The two passwords do not match");
  }

  // first check the database to make sure 
  // a user does not already exist with the same username and/or email
  $customer_check_query = "SELECT * FROM customer WHERE name='$name' OR email='$email' OR phone='$phone' OR address='$address' LIMIT 1";
  $result = mysqli_query($db, $customer_check_query);
  $customer = mysqli_fetch_assoc($result);
  
  if ($customer) { // if user exists
    if ($customer['name'] === $name) {
      array_push($errors, "Username already exists");
    }

    if ($customer['email'] === $email) {
      array_push($errors, "email already exists");
    }

    if ($customer['phone'] === $phone) {
        array_push($errors, "phone already exists");
    }

  }

  // Finally, register user if there are no errors in the form
  if (count($errors) == 0) {
  	$password = md5($password_1);//encrypt the password before saving in the database

  	$query = "INSERT INTO customer (name, email, phone, address,password) 
  			  VALUES('$name', '$email', '$phone', '$address', '$password')";
  	mysqli_query($db, $query);
  	$_SESSION['name'] = $name;
  	$_SESSION['success'] = "You are now logged in";
  	header('location: Csignup.php');
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
          background-image: url("cus.jpg");
          background-repeat: no-repeat;
          background-size: 1550px 950px;
  }
        
  </style>
  
</head>
<body>
  <div class="header">
  	<h2>Customer Register</h2>
  </div>
	
  <form id="form" method="post" action="Csignup.php">
  	<?php if (count($errors) > 0) : ?>
  <div class="error">
  	<?php foreach ($errors as $error) : ?>
  	  <p><?php echo $error ?></p>
  	<?php endforeach ?>
  </div>
<?php  endif ?>
  	<div class="input-group">
  	  <label>Username</label>
  	  <input type="text" id="name" name="name" value="<?php echo $name; ?>">
  	</div>
  	<div class="input-group">
  	  <label>Email</label>
  	  <input type="email" id="email" name="email" value="<?php echo $email; ?>">
  	</div>
      <div class="input-group">
  	  <label>Phone</label>
  	  <input type="phone" id="phone" name="phone" value="<?php echo $phone; ?>">
  	</div>
      <div class="input-group">
  	  <label>Address</label>
  	  <input type="address" id="address" name="address" value="<?php echo $address; ?>">
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
  		Already a customer? <a href="Clogin.php">Sign in</a>    <a href="home.html">Home</a>
  	</p>
  </form>
</body>
</html>