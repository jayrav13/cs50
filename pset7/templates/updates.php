<?php if(isset($user) && $user[0]["admin"] == 1) { ?>

    <form action="updates.php" method="post">
        <fieldset>  
            <div class="form-group">
                <textarea autofocus autocomplete = "off" class="form-control" name="text" placeholder="Enter Update" type="text" cols = 50 rows = 3></textarea>
            </div>
            <div class="form-group">
                <button name = "add" type="submit" class="btn btn-default">Submit Update</button>
            </div>
        </fieldset>
    </form>

<?php } ?>

<table class = "table table-striped" style = "text-align:left">
    <thead><tr><th width = 75>User</th><th width = 200>Date</th><th>Update</th></tr></thead>
    
    <?php

        if(isset($updates) && isset($user))
        {
            foreach($updates as $update)
            {
                printf("<tr>");
                printf("<td>" . $update["username"]. "</td>");
                printf("<td>" . $update["date"] . "</td>");
                printf("<td>" . $update["text"] . "</td>");
                printf("</tr>");
            }
        }
    
    ?>
</table>