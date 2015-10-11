<table class = "table table-striped" style = "text-align:left">
    <thead><tr><th>Name</th><th>Symbol</th><th>No. Shares</th><?php if(isset($user) && $user[0]["id"] == 53){ echo "<th>Orig. Price</th>"; }?><th>Current Price</th><th>TOTAL</th></tr></thead>
    
    <?php
        if(isset($data))
        {
            foreach($data as $rows)
            {
                printf("<tr>");
                printf("<td>" . $rows["name"] . "</td>");
                printf("<td>" . $rows["symbol"] . "</td>");
                printf("<td>" . $rows["shares"] . "</td>");
                if(isset($user) && $user[0]["id"] == 53)
                {
                    printf("<td>$ " . $rows["purchase_price"] . "</td>");
                }
                printf("<td>$ " . number_format($rows["price"], 2) . "</td>");
                printf("<td>$ " . number_format($rows["price"] * $rows["shares"], 2) . "</td>");
                printf("</tr>");
            }
        }
        if(isset($user))
        {
            printf("<tr><td><b>CASH</b></td><td></td><td></td><td></td><td><b>$ " . number_format($user[0]["cash"], 2) . "</b></td></tr>");
        }
    
    ?>
</table>