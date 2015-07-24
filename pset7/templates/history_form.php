<table class = "table table-striped" style = "text-align:left">
    <thead><tr><th>Transaction</th><th>Date/Time</th><th>Symbol</th><th>Shares</th><th>Price</th><th>Total Cost</th></tr></thead>
    
    <?php
        if(isset($history))
        {
            foreach($history as $rows)
            {
                printf("<tr>");
                printf("<td>" . $rows["transaction"] . "</td>");
                printf("<td>" . $rows["date"] . "</td>");
                printf("<td>" . $rows["symbol"] . "</td>");
                printf("<td>" . $rows["shares"] . "</td>");
                printf("<td> $ " . number_format($rows["price"],2) . "</td>");
                printf("<td> $ " . number_format($rows["price"] * $rows["shares"], 2) . "</td>");
                printf("</tr>");
            }
        }
    
    ?>
</table>