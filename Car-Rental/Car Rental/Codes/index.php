<?php 
  session_start(); 

  if (!isset($_SESSION['name'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: Alogin.php');
  }
  if (isset($_GET['logout'])) {
  	session_destroy();
  	unset($_SESSION['name']);
  	header("location: Alogin.php");
  }
?>
<!DOCTYPE html>
<html>
<head>
	<title>Home</title>
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


<div class="header" action="Addcar.php">
	<h2>Home Page</h2>
</div>
<div class="content">
  	<!-- notification message -->
  	<?php if (isset($_SESSION['success'])) : ?>
      <div class="error success" >
      	<h3>
          <?php 
          	echo $_SESSION['success']; 
          	unset($_SESSION['success']);
          ?>
      	</h3>
      </div>
  	<?php endif ?>

    <!-- logged in user information -->
    <?php  if (isset($_SESSION['name'])) : ?>
    	<p>Welcome <strong><?php echo $_SESSION['name']; ?></strong></p>
    	<p> <a href="index.php?logout='1'" style="color: red;">logout</a></p> 
		<p>Add a new Admin, <a href="Asignup.php">click here</a> </p>
    <?php endif ?>
  

  <p> <a href="Addcar.php">  
   <button type="button" class="btn">Add new car</button>
   </a> 
    <a href="Addoffice.php">  
   <button type="button" class="btn">Add new office</button>
   </a>
    <a href="Changestatus.php">  
   <button type="button" class="btn">Change car status</button>
   </a>
   
    <a href=" AdvancedSearch.php">  
   <button type="button" class="btn">Advanced reservation search</button>
   </a>
    </p>

     <a href=" carsearch_admin.php">  
   <button type="button" class="btn">Advanced car search</button>
   </a>
    </p>

     <a href=" customersearch_admin.php">  
   <button type="button" class="btn">Advanced customer search</button>
   </a>
    </p>

     <a href=" dailypayment.php">  
   <button type="button" class="btn">Daily Payments on specific period</button>
   </a>
    </p>

    <a href=" dailypayment2.php">  
   <button type="button" class="btn">Payments on specific period</button>
   </a>
    </p>
   
</div>
		

</body>

</html>