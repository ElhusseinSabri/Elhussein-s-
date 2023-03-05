<!DOCTYPE html>


<?php require_once('functions.php');




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
            
            case 'resdate1':
                array_push($queries, " '$resdate1'");
                break;
            case 'resdate2':
                array_push($queries, " '$resdate2'");
                break;
        }
    }
}

$resdate1 = isset($resdate1) ? $resdate1 : "";
$resdate2 = isset($resdate2) ? $resdate2 : "";


$sql1 =" SELECT day as dpd ,sum(payments) as dpp FROM dailypayment WHERE day BETWEEN '$resdate1' AND '$resdate2' GROUP by day";
$sql2 =" SELECT sum(payments) as dps FROM dailypayment WHERE day BETWEEN '$resdate1' AND '$resdate2'";



$rs = mysqli_query($conn,$sql1) or die(mysqli_connect_error());
$rows = mysqli_fetch_array($rs);
$numrows=mysqli_num_rows($rs);


$rs2 = mysqli_query($conn,$sql2) or die(mysqli_connect_error());
$rows2 = mysqli_fetch_array($rs2);
$tot=$rows2['dps'];



?>

<html>
    <head>
        <title>Search daily payments</title>
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
                    <h2>Search Daily Payments</h2>
                    <h3>Find Daily payments</h3>
                </div>
            </div>
            <div id="wp">
                <div id="header">
                    <div id="container">
                    <form id="srch_form" name="srch_form" method="get" action="">
                        <table border="2" cellpadding="3" cellspacing="4">
                       
                         <tr>
                            <th scope="row" class="mheader">Specific period</th>
                            <th class="sheader">From</th>
                            <td><input type="date" name="resdate1" id="resdate1" value="<?php if(isset($_GET['resdate1'])) {echo $_GET['resdate1'];} ?>"/></td>
                            <th class="sheader">To</th>
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
                            
                            <th scope="col" class="tbl2c">Day</th>
                            <th scope="col" class="tbl2c">Total payment</th>
                           
                            
                        </tr>
                       <?php do {   ?>
            

            <tr>
                <td><?php echo $rows['dpd']; ?> </td>
                <td><?php echo $rows['dpp']; ?> </td>
                
                
                
            </tr>


                    <?php } while($rows = mysqli_fetch_array($rs)); ?>

                  
                    </table> <?php } ?>
                    <table border="1" cellpadding="1" cellspacing="1" class="tbl2">
                             <tr>
                            
                          
                           
                            
                        </tr>
                       <?php do {   ?>
            

            <tr>
                 <td><?php echo 'Total summation of payments'; ?> </td>
                <td><?php echo $tot; ?> </td>
              
                
                
            </tr>
                <?php } while($rows2 = mysqli_fetch_array($rs2)); ?>
                         </table>
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