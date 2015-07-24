<?php 
    if(!isset($data))
    {
        redirect("/");
    }

?>

<form action="settings.php" method="post" autocomplete = "off">
    <fieldset>
        <div class="form-group">
            <input readonly class="form-control" style = "text-align:center" name="username" placeholder="Username" value = <?php echo $data[0]["username"]; ?> type="text"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="password" placeholder="New Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Confirm Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="email" placeholder="New Email" value = <?php echo $data[0]["email"]; ?> type="text"/>
        </div>
        <div class="form-group">
            Admin Access
            
            <?php 
                if($data[0]["admin"] == 1) 
                {
                    echo "<i style = \"color:green\" class = \"glyphicon glyphicon-ok\"></i>";
                }
                else
                {
                    echo "<i style = \"color:red\" class = \"glyphicon glyphicon-remove\"></i>";
                }
            ?>
            
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Update Settings</button>
        </div>
    </fieldset>
</form>