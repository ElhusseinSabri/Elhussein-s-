<!DOCTYPE html>
<?php require_once('functions.php');

// $sql1 = "SELECT DISTINCT cu.customer_id AS CustomerID, cu.name as `Name`, c.plate_id as PlateID, c.category_name as category_name, c.model as Model,
// c.year as `year`, r.reserve_id as ReservationID, r.reserve_date as ReservationDate, r.payment as Payment, c.year as `Year` , cu.email as Email, cu.address as `Address`
// FROM customer cu

// JOIN reservation r
// on cu.customer_id = r.customer_id

// JOIN car c
// on r.plate_id = c.plate_id


// ";

$sql1="SELECT DISTINCT cu.customer_id AS CustomerID, cu.name as `Name`, cu.email as Email, cu.address as `Address`,cu.phone as p from customer cu";

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
            
            case 'custid':
                array_push($queries, "cu.customer_id = '$custid'");
                break;

            case 'custname':
                array_push($queries, " cu.name = '$custname'");
                break;

            case 'custemail':
                array_push($queries, " cu.email = '$custemail'");
                break;

            case 'custphno':
                array_push($queries, " cu.phone = '$custphno'");
                break;

            case 'custaddr':
                array_push($queries, " cu.address = '$custaddr'");
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

//$sql1 .= " ORDER BY cu.customer_id ASC";
}


$rs = mysqli_query($conn,$sql1) or die(mysqli_connect_error());
$rows = mysqli_fetch_array($rs);
$numrows=mysqli_num_rows($rs);

?>

<html>
    <head>
        <title>Advanced customer search</title>
        <link rel="stylesheet" href="stylee.css">
        <style>
	     body {
          margin: 0px;
          padding: 100px;
          font-size: 120%;
          background-image: url("pag.png");
          background-repeat: no-repeat;
          background-size: 1550px 1050px;
  }
        
  </style>
    </head>
    <body>
        <div id="out">
            <div id="pheader">
                <div id="pheaderin">
                    <h2>Search by Customer</h2>
                    <h3>Find  customer information</h3>
                </div>
            </div>
            <div id="wp">
                <div id="header">
                    <div id="container">
                    <form id="srch_form" name="srch_form" method="get" action="">
                        <table border="2" cellpadding="3" cellspacing="4">
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
                            <th class = "sheader"><label for="custaddr">Address </label></th>
                            <td><input type="text" name="custaddr" id="custaddr"/></td>
                        </tr>
                                <td colspan="12"><label for="button" class="btn">
                                    <input type="submit" id="button" value="Search"/>
                                </label></td>
                            </tr>

                        </table>
                    </form>
                    <?php if($numrows > 0) { ?>
                    <table border="1" cellpadding="1" cellspacing="1" class="tbl2">
                        <tr>
                            <th scope="col" class="tbl2c">Customer ID</th>
                            <th scope="col" class="tbl2c">Customer Name</th>
                            <th scope="col" class="tbl2c">Customer E-mail</th>
                            <th scope="col" class="tbl2c">Phone Number</th>
                            <th scope="col" class="tbl2c">Address</th>
                            
                        </tr>
                       <?php do {   ?>
            

            <tr>
                <td><?php echo $rows['CustomerID']; ?></td>
                <td><?php echo $rows['Name']; ?> </td>
                <td><?php echo $rows['Email'] ?> </td>
                <td><?php echo $rows['p'] ?> </td>
                <td><?php echo $rows['Address'] ?> </td>
            </tr>
                    <?php } while($rows = mysqli_fetch_array($rs)); ?>

                    </table> <?php } ?>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>
<?php mysqli_free_result($rs); ?>