<?php 
  session_start(); 

 


// initializing variables
$plate_id = "";
$customer_id="";

$errors = array(); 
$resdate1="";
$resdate2="";
$payment="";
$total_price="";
$i=1;
$carstatus="";
$day="";
$daily_price="";
$cusname=$_SESSION['name'];
// connect to the database
$db = mysqli_connect('localhost', 'root', '', 'Car_Rental_System');
$idquery="SELECT customer_id FROM customer WHERE name='$cusname' ";
$resu = mysqli_query($db, $idquery);
$admin = mysqli_fetch_assoc($resu);
$customer_id=$admin['customer_id'];





$datequery="SELECT DATEDIFF('$resdate2', '$resdate1') as dd";
$resdate= mysqli_query($db, $datequery);
$datedifff = mysqli_fetch_assoc($resdate);
$datt=$datedifff['dd'];
echo $datt;
$total_price=$datt*10;









 
if (isset($_POST['change_carstatus'])) {
	$plate_id = mysqli_real_escape_string($db, $_POST['plate_id']);
	$resdate1 = mysqli_real_escape_string($db, $_POST['resdate1']);
	$resdate2 = mysqli_real_escape_string($db, $_POST['resdate2']);
	$payment = mysqli_real_escape_string($db, $_POST['payment']);



  
	if (empty($plate_id)) {
		array_push($errors, "A plate_id is required");
	}
	
  
	if (count($errors) == 0) {
		 
		
		$query = "SELECT * FROM car WHERE plate_id='$plate_id' And Available ='yes' ";
		$results = mysqli_query($db, $query);
		$ad= mysqli_fetch_assoc($results);

		if (mysqli_num_rows($results) == 1) {
		 // $_SESSION['name'] = $name;
		  //$_SESSION['success'] = "You are now logged in";
		  //header('location: Cindex.php');
		 /*  $day=$resdate1;
     $q1="SELECT carstatus FROM car_status where plate_id='$plate_id' AND day='$resdate1' AND carstatus='Active' ";
     $r1 = mysqli_query($db, $q1);
     $q2="SELECT carstatus FROM car_status where plate_id='$plate_id' AND day='$resdate2' AND carstatus='Active' ";
     $r2 = mysqli_query($db, $q2);
     $q3="SELECT carstatus  FROM car_status where plate_id='$plate_id' AND day=DATE_ADD('$resdate1', INTERVAL '$i' DAY) AND carstatus='Active' ";
     $r3 = mysqli_query($db, $q3);
     $day = strtotime("+$i day", strtotime($resdate1));
     while ($day!=$resdate2){
             $i++;
             $day = strtotime("+$i day", strtotime($resdate1));
            $q3="SELECT carstatus FROM car_status where plate_id='$plate_id' AND day=DATE_ADD('$resdate1', INTERVAL '$i' DAY) AND carstatus='Active' ";
            $r3=$r3 = mysqli_query($db, $q3);
            

     }*/

    // if($r1 && $r2 && $r3){
     $q1="SELECT daily_price FROM car WHERE plate_id='$plate_id'";
     $results = mysqli_query($db, $q1);
     $a= mysqli_fetch_assoc($results);
     $daily_price=$a['daily_price'];
   
      



		  	$query1 = "INSERT INTO reservation (plate_id,customer_id,pickup_date,return_date,payment,total_price) 
  			  VALUES('$plate_id', '$customer_id','$resdate1','$resdate2','$payment','$total_price')";
          $results1 = mysqli_query($db, $query1);

        $q2="UPDATE car SET Available ='no' where plate_id='$plate_id' ";
       $results2 = mysqli_query($db, $q2);
       $qid="SELECT reserve_id from reservation where plate_id='$plate_id' AND customer_id='$customer_id' AND pickup_date='$resdate1' ";
       $resid = mysqli_query($db, $qid);
       $aid= mysqli_fetch_assoc($resid);
       $res_id=$aid['reserve_id'];
    



$qp = "INSERT INTO dailypayment (reserve_id, payments,day) 
  			  VALUES('$res_id', '$daily_price','$resdate1')";

  			  $qp2 = "INSERT INTO dailypayment (reserve_id, payments,day) 
  			  VALUES('$res_id', '$daily_price','$resdate2')";

		     $resultsp = mysqli_query($db, $qp);
		     $resultsp2 = mysqli_query($db, $qp2);
		     $qp3="INSERT INTO dailypayment (reserve_id, payments,day) 
  			  VALUES('$res_id', '$daily_price',DATE_ADD('$resdate1', INTERVAL '$i' DAY))";
		      $resultsp3=mysqli_query($db,$qp3);
		  while($resultsp3){
		  	$i++;
		  	 $queryp3="INSERT INTO dailypayment (reserve_id, payments,day) 
  			  VALUES('$res_id', '$daily_price',DATE_ADD('$resdate1', INTERVAL '$i' DAY))";
		  	
		  	try{
		  		$resultsp3=mysqli_query($db,$queryp3);
		  	}
		  	catch(Exception $e){
		  		break;
		  	}

      }
      $sql2 =" SELECT sum(payments) as dps FROM dailypayment WHERE reserve_id='$res_id'";
      $rs2 = mysqli_query($db,$sql2) or die(mysqli_connect_error());
      $rows2 = mysqli_fetch_array($rs2);
      $tot=$rows2['dps'];
     $qq2="UPDATE reservation SET total_price ='$tot' where reserve_id='$res_id' ";
       $resultsq2 = mysqli_query($db, $qq2);
      

  		   
  		//    $query = "UPDATE car_status SET carstatus ='Rented' where $plate_id='$plate_id' AND day='$resdate1'";
  		// 	 $query2 = "UPDATE car_status SET carstatus ='Rented' where $plate_id='$plate_id' AND day='$resdate2'";

		  //    $results = mysqli_query($db, $query);
		  //    $results2 = mysqli_query($db, $query2);
		  //    $query3="UPDATE car_status SET carstatus ='Rented' where $plate_id='$plate_id' AND day=DATE_ADD('$resdate1', INTERVAL '$i' DAY)";
		  //     $results3=mysqli_query($db,$query3);
		  // while($results3){
		  // 	$i++;
		  // 	 $query3="UPDATE car_status SET carstatus ='Rented' where $plate_id='$plate_id' AND day=DATE_ADD('$resdate1', INTERVAL '$i' DAY)";
		  	
		  // 	try{
		  // 		$results3=mysqli_query($db,$query3);
		  // 	}
		  // 	catch(Exception $e){
		  // 		break;
		  // 	//}
		  //   //}
		  //   // }
		

		}else {
			   array_push($errors, "car unavailable ");
		}
	}
  }
   ?>
<!DOCTYPE html>
<html>
<head>
  <title>Reserve a car</title>


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
  	<h2>Reserve a car </h2>
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
  			<label>Payment : </label>
			<label for="Cash">Cash on pickup</label>
			<input type="radio" class="rb" id="Cash" name="payment" value="Cash">
			<label for="Visa">Visa</label>
			<input type="radio" class="rb" id="Visa" name="payment" value="Visa">
			<label for="Check">Check on pickup</label> 
			<input type="radio"  class="rb"id="Check" name="payment" value="Check">


						<div class=date1>
							<label for="resdate1">From</label>
							<input type="date" name="resdate1" id="resdate1" value="">
							<label for="resdate2">To</label>
							<input type="date" name="resdate2" id="resdate2" value="">

						</div>


                      	   
  	</div>
  	<div class="input-group">
  		<button type="submit" class="btn" name="change_carstatus">Reserve</button>
  	</div>
  	<p>
  		  <a href="home.html">Home</a>
  	</p>
  	<p>
  		  <a href="Cindex.php">Customer Page</a>
  	</p>
	
  </form>
  
</body>
</html>