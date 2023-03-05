<!DOCTYPE html>
<?php require_once('functions.php');



#JOIN car c
#on c.plate_id = cs.plate_id



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
        }
    }
}

// if(!empty($queries))
// {
//     $sql1 .= " WHERE ";
//     $i = 1;
//     foreach($queries as $q){
//     if($i < count($queries))
//     {
//         $sql1 .= $q. " AND ";
//     }else
//     {
//         $sql1 .= $q;
//     }
//     $i++;
// }

// $sql1 .= " ORDER BY cs.day ASC";
// }

$sql1 = "SELECT  cs.day as csd, cs.plate_id as csp, cs.carstatus as csc  
FROM car_status cs where cs.day='$resdate1'";

$rs = mysqli_query($conn,$sql1) or die(mysqli_connect_error());
$rows = mysqli_fetch_array($rs);
$numrows=mysqli_num_rows($rs);

?>

<html>
    <head>
        <title>Status car search</title>
        <link rel="stylesheet" href="stylee.css">
        <script>

        </script>
    </head>
    <body>
        <div id="out">
            <div id="pheader">
                <div id="pheaderin">
                    <h2>Cars status</h2>
                    <h3>Find The status of all cars on a specific day.:</h3>
                </div>
            </div>
            <div id="wp">
                <div id="header">
                    <div id="container">
                    <form id="srch_form" name="srch_form" method="get" action="">
                        <table border="2" cellpadding="3" cellspacing="4">
                       
                       
                            <tr>
                            <th scope="row" class="mheader">Specific Date:</th>
                            <th class="sheader">At:</th>
                            <td><input type="date" name="resdate1" id="resdate1" value=""/></td>
                      
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
                            
                            <th scope="col" class="tbl2c">Date</th>
                            <th scope="col" class="tbl2c">Plate ID</th>
                            <th scope="col" class="tbl2c">Car Status</th>
                            
                        </tr>
                       <?php do {   ?>
            

            <tr>
                <td><?php echo $rows['csd']; ?> </td>
                <td><?php echo $rows['csp']; ?> </td>
                <td><?php echo $rows['csc']; ?> </td>
                
                
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