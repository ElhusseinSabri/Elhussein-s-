<?php 
  session_start(); 


 

?>
<!DOCTYPE html>
<?php require_once("functions.php"); 

$cusname= $_SESSION['name'];
$idquery="SELECT customer_id FROM customer WHERE name='$cusname' ";
$resu = mysqli_query($conn, $idquery);
$admin = mysqli_fetch_assoc($resu);
$customer_id=$admin['customer_id'];


$sql = "SELECT r.reserve_id as res_id ,r.plate_id as plate_id , r.customer_id as cus_id ,
r.pickup_date as pickup_date ,r.return_date as return_date , r.payment as payment , r.reserve_date as reserve_date , r.total_price as total_price
 FROM reservation r where r.customer_id='$customer_id'
 
 ";



$gets = array();
$queries = array();

foreach($_GET as $key => $value)
{
    $temp = is_array($value) ? $value : trim($value);
    if(!empty($temp))
    {
        list($key) = explode("-",$key);
        if($key == 'category_name'){
            array_push($categories,"'$value'");
        }
        if(!in_array($key,$gets))
        {
            $gets[$key]=$value;
        }
    }
}

// if(!empty($categories))
// {
//     $catquery = implode(",",$categories);
// }

// if(!empty($gets))
// {
//     foreach($gets as $key => $value)
//     {   ${$key} = $value;
//         switch($key){
//             case 'category_name' :
//                 array_push($queries," c.category_name IN ($catquery)");
//                 break;
//             case 'model':
//                 array_push($queries," c.model = '$model'");
//                 break;
//             case 'year':
//                 array_push($queries," c.year = $year");
//                 break;
//             case 'startprice':
//                 array_push($queries," c.daily_price >= '$startprice'");
//                 break;
//             case 'endprice':
//                 array_push($queries,"c.daily_price <= '$endprice'");
//                 break;
//             case 'city':
//                 array_push($queries,"of.city = '$city'");
//                 break;
            
//             case 'plate_id':
//                 array_push($queries," c.plate_id = '$plate_id'");
//         }
//     }
// }

// if(!empty($queries))
// {
//     $sql .= " AND ";
//     $j = 1;
//     foreach($queries as $q)
//     {
//         if($j < count($queries))
//         {
//             $sql .= $q. " AND ";

//         }else {
//             $sql .=$q;
//         }
//         $j++;
//     }
// }
$sql .= " ORDER BY reserve_id";
$rs = mysqli_query($conn,$sql) or die(mysqli_connect_error());
$rows = mysqli_fetch_array($rs);
$numrows=mysqli_num_rows($rs);



?>
<html>
    <head>
        <title>My reservations</title>
        <link rel="stylesheet" href="style1.css">
        <style>
	     body {
          margin: 0px;
          padding: 300px;
          font-size: 120%;
          background-image: url("pag.png");
          background-repeat: no-repeat;
          background-size: 1550px 1050px;
  }
        
  </style>
    </head>
    <body>
        <div id="ph">
            <div id="phin">
                <h2>My Reservations</h2>
                
            </div>
        </div>
        <div id="card1">
            <div id="container">
                <form id="fltrform" name="fltrform" action="" method="get">
                   
                </form>
                <?php if($numrows=mysqli_num_rows($rs)) { ?>
                <table border="1" cellpadding="2" cellspacing="2" class="restbl">
                        <tr>
                            <th scope="col" class="rescol">Reservation ID</th>
                            <th scope="col" class="rescol">Plate ID</th>
                            <th scope="col" class="rescol">Customer ID</th>
                            <th scope="col" class="rescol">Pickup date</th>
                            
                            <th scope="col" class="rescol">Return date</th>
                           <th scope="col" class="rescol">Reservation date</th>
                            <th scope="col" class="rescol">Payment</th>
                            <th scope="col" class="rescol">Total Price </th>
                            
                        </tr>

                        <?php do { ?>
                        <tr>
                            <td><?php echo $rows['res_id']; ?></td>
                            <td><?php echo $rows['plate_id']; ?></td>
                            <td><?php echo $rows['cus_id']; ?></td>
                            <td><?php echo $rows['pickup_date']; ?></td>
                            <td><?php echo $rows['return_date']; ?></td>
                             <td><?php echo $rows['reserve_date']; ?></td>
                          
                            <td><?php echo $rows['payment']; ?></td>
                            <td><?php echo $rows['total_price']; ?></td>
                        </tr>
                        <?php }while($rows = mysqli_fetch_array($rs)); ?>
                </table>
                <?php } ?>

    </p>
            </div>
             
        </div>
</body>

</html>
<?php mysqli_free_result($rs); ?>