<!DOCTYPE html>
<?php require_once('functions.php');

$sql1 = "SELECT DISTINCT cu.customer_id AS CustomerID, cu.name as `Name`, c.plate_id as PlateID, c.category_name as category_name,
c.year as `year`, r.reserve_id as ReservationID, r.reserve_date as ReservationDate, r.payment as Payment, c.year as `Year` 
FROM customer cu

JOIN reservation r
on cu.customer_id = r.customer_id

JOIN car c
on r.plate_id = c.plate_id

";

$gets = array();
$queries = array();

foreach ($_GET as $key => $value) {
    $temp = is_array($value) ? $value : trim($value);
    if(!empty($temp))
    {
        list($key) = explode("-",$key);
        if(!in_array($key,$gets))
        {
            $gets[$key] = $value;
        }

    }
}

if(!empty($gets))
{
    foreach($gets as $key => $value)
    {
        ${$key} = $value;
        switch($key)
        {
            case 'category_name':
                array_push($queries," category_name = '$category_name'");
                break;

            case 'year':
                array_push($queries, " c.year = '$year'");
                break;

            case 'plate_id':
                array_push($queries, " c.plate_id = '$plate_id'");
                break;


            case 'custid':
                array_push($queries, "cu.customer_id = '$custid'");
                break;

            case 'custname':
                array_push($queries, " cu.name LIKE '%$custname%'");
                break;

            case 'custemail':
                array_push($queries, " cu.email = '$custemail'");
                break;

            case 'custphno':
                array_push($queries, " cu.phone = '$custphno'");
                break;

            case 'resdate1':
                array_push($queries, "r.reserve_date BETWEEN '$resdate1'");
                break;

            case 'resdate2':
                array_push($queries, " '$resdate2'");
                break;
        }
    }
}

if(!empty($queries))
{
    $sql1 .= " WHERE ";
    $i = 1;
    foreach($queries as $q){
    if($i < count($queries))
    {
        $sql1 .= $q. " AND ";
    }else
    {
        $sql1 .= $q;
    }
    $i++;
}

$sql1 .= " ORDER BY r.reserve_date ASC";
}


$rs = mysqli_query($conn,$sql1) or die(mysqli_connect_error());
$rows = mysqli_fetch_array($rs);
$numrows=mysqli_num_rows($rs);

?>

<html>
    <head>
        <title>Advanced Search</title>
        <link rel="stylesheet" href="stylee.css">
       
        <style>
	     body {
          margin: 0px;
          padding: 100px;
          font-size: 120%;
          background-image: url("pag.png");
          background-repeat: no-repeat;
          background-size: 1950px 1050px;
  }
        
  </style>
    </head>
    <body>
        <div id="out">
            <div id="pheader">
                <div id="pheaderin">
                    <h2>Advanced Search</h2>
                    <h3>Find reservations by car information, customer information or reservation status:</h3>
                </div>
            </div>
            <div id="wp">
                <div id="header">
                    <div id="container">
                    <form id="srch_form" name="srch_form" method="get" action="">
                        <table border="2" cellpadding="3" cellspacing="4">
                        <tr>
                            <th scope="row" class="mheader">Car information</th>
                            <th class = "sheader"><label for="category_name">Category</label></th>
                            <td><?php echo getCategory(); ?></td>
                            <th class = "sheader"><label for="year">Year</label></th>
                            <td><?php echo getYear(); ?></td>
                            <th class = "sheader">Plate number</th>
                            <td><input type="number" name="plate_id" id="plate_id"/></td>
                         
                        </tr>
                        <tr>
                            <th scope="row" class="mheader">Customer information</th>
                            <th class = "sheader"><label for="custid">Customer ID</label></th>
                            <td><input type="number" name="custid" id="custid"/></td>
                            <th class = "sheader"><label for="custname">Name</label></th>
                            <td><input type="text" name="custname" id="custname"/></td>
                            <th class = "sheader"><label for="custemail">E-mail</label></th>
                            <td><input type="email" name="custemail" id="custemail" /></td>
                            <th class = "sheader"><label for="custphno">Phone Number</label></th>
                            <td><input type="number" name="custphno" id="custphno"/></td>
                            </tr>
                            <tr>
                            <th scope="row" class="mheader">Reservation Date:</th>
                            <th class="sheader">From:</th>
                            <td><input type="date" name="resdate1" id="resdate1" value="<?php if(isset($_GET['resdate1'])) {echo $_GET['resdate1'];} ?>"/></td>
                            <th class="sheader">To:</th>
                            <td><input type="date" name="resdate2" id="resdate2" value="<?php if(isset($_GET['resdate2'])) {echo $_GET['resdate2'];} ?>"/></td>
                            </tr>
                            <tr>
                                <td colspan="9"><label for="button" class="btn">
                                    <input type="submit" id="button" value="Search"/>
                                </label></td>
                            </tr>

                        </table>
                    </form>
                    <?php if($numrows > 0) { ?>
                    <table border="1" cellpadding="1" cellspacing="1" class="tbl2">
                        <tr>
                            <th scope="col" class="tbl2c">Reservation ID</th>
                            <th scope="col" class="tbl2c">Reservation Date</th>
                            <th scope="col" class="tbl2c">Plate ID</th>
                            <th scope="col" class="tbl2c">Year</th>
                            <th scope="col" class="tbl2c">Customer ID</th>
                            <th scope="col" class="tbl2c">Customer Name</th>
                            <th scope="col" class="tbl2c">Payment</th>
                        </tr>
                       <?php do {   ?>
            

            <tr><td><?php echo $rows['ReservationID']; ?></td>
                <td><?php echo $rows['ReservationDate']; ?> </td>
                <td><?php echo $rows['PlateID']; ?> </td>
                <td><?php echo $rows['Year']; ?> </td>
                <td><?php echo $rows['CustomerID']; ?></td>
                <td><?php echo $rows['Name']; ?> </td>
                <td><?php echo $rows['Payment']; ?></td>
            </tr>
                    <?php } while($rows = mysqli_fetch_array($rs)); ?>

                    </table> <?php } ?>
                    </div>
                </div>
            </div>
        </div>
        <div id="footer">
            <div id="ftin">
            </div>
        </div>
    </body>
</html>
<?php mysqli_free_result($rs); ?>