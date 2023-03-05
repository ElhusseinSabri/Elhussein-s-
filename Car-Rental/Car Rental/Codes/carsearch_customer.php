<?php 
  session_start(); 


 

?>
<!DOCTYPE html>
<?php require_once("functions.php"); 

$sql = "SELECT DISTINCT  c.model as Model, c.year as `Year`, c.daily_price as payment,
 c.plate_id as PlateID, c.office_id as OfficeID ,c.category_name as category , of.city as office_city
 FROM car c 

join office of on of.office_id=c.office_id 

where c.Available = 'yes'


 
 ";

$categories = array();
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

if(!empty($categories))
{
    $catquery = implode(",",$categories);
}

if(!empty($gets))
{
    foreach($gets as $key => $value)
    {   ${$key} = $value;
        switch($key){
            case 'category_name' :
                array_push($queries," c.category_name IN ($catquery)");
                break;
            case 'model':
                array_push($queries," c.model = '$model'");
                break;
            case 'year':
                array_push($queries," c.year = $year");
                break;
            case 'startprice':
                array_push($queries," c.daily_price >= '$startprice'");
                break;
            case 'endprice':
                array_push($queries,"c.daily_price <= '$endprice'");
                break;
            case 'city':
                array_push($queries,"of.city = '$city'");
                break;
            
            case 'plate_id':
                array_push($queries," c.plate_id = '$plate_id'");
        }
    }
}

if(!empty($queries))
{
    $sql .= " AND ";
    $j = 1;
    foreach($queries as $q)
    {
        if($j < count($queries))
        {
            $sql .= $q. " AND ";

        }else {
            $sql .=$q;
        }
        $j++;
    }
}
$sql .= " ORDER BY c.daily_price ASC";
$rs = mysqli_query($conn,$sql) or die(mysqli_connect_error());
$rows = mysqli_fetch_array($rs);
$numrows=mysqli_num_rows($rs);



?>
<html>
    <head>
        <title>Find a Car</title>
        <link rel="stylesheet" href="style1.css">
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
        <div id="ph">
            <div id="phin">
                <h2>Find a Car</h2>
                <h3>Search All Available Cars by Specs</h3>
            </div>
        </div>
        <div id="card1">
            <div id="container">
                <form id="fltrform" name="fltrform" action="" method="get">
                    <table border="1" cellpadding="3" cellspacing="3">
                        <tr>
                        <th class="row" scope="row">Category</th>
                        <td  class="ip" colspan="10"><?php echo getCategories(); ?></td>
                        </tr>

                        <tr>
                        <th class="row">Model</th>
                        <td colspan="10" class="ip"><input type="text" name="model" id="model" /></td>
                        </tr>

                        <tr>
                        <th class="row">Year</th>
                        <td class="ip" colspan="10"><?php echo getYear(); ?></td>
                        </tr>

                        <tr>
                        <th class="row">Plate ID</th>
                        <td class="ip" colspan="10"><input type="number" name="plate_id" id="plate_id" /></td>

                        <tr>



                        <tr>
                        <th class="row">City </th>
                        <td class="ip" colspan="10"><?php echo getCity(); ?></td>

                        <tr>

                            <th class="row" colspan ="2">Daily Payment</th>
                            <td class="ip" colspan="4"><label for="startprice">From</label><input type="number" name="startprice" id="startprice" value=""/></td>
                            <td class="ip" colspan="4"><label for="endprice">To</label><input type="number" name="endprice" id="endprice" value=""/></td>
                        </tr>

                        

                        <tr>
                                <td colspan="10"><label for="button" class="btn">
                                    <input type="submit" id="button" value="Search"/>
                                </label></td>
                                <td colspan="10"><a href=" Reservation.php">  
                       <button type="button" class="bt">Reserve a car by plate id</button>

                         </a></td>
                         <td colspan="10"><a href=" myreservations.php">  
                       <button type="button" class="bt">My Reservations</button>

                         </a></td>
                            </tr>

                            <tr>
                                
                            </tr>
                    </table> 
                </form>
                <?php if($numrows=mysqli_num_rows($rs)) { ?>
                <table border="1" cellpadding="2" cellspacing="2" class="restbl">
                        <tr>
                            <th scope="col" class="rescol">Category</th>
                            <th scope="col" class="rescol">Model</th>
                            <th scope="col" class="rescol">Year</th>
                            <th scope="col" class="rescol">Plate ID</th>
                            
                            <th scope="col" class="rescol">Office City</th>
                    
                            <th scope="col" class="rescol">Daily Payment</th>
                            
                        </tr>

                        <?php do { ?>
                        <tr>
                            <td><?php echo $rows['category']; ?></td>
                            <td><?php echo $rows['Model']; ?></td>
                            <td><?php echo $rows['Year']; ?></td>
                            <td><?php echo $rows['PlateID']; ?></td>
                            <td><?php echo $rows['office_city']; ?></td>
                          
                            <td><?php echo "&pound;".$rows['payment']; ?></td>
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