<table class = "table table-striped" style = "text-align:left" width = 300>
    <thead><tr><th>Rank</th><th>Company</th><th>Ticker</th><th width = "150">Current Price</th><th width = "100" style = "text-align:center">Total Trades</th></tr></thead>
    
    <?php

        if(isset($data))
        {
            $count = 0;

            foreach($data as $row)
            {
                $ticker = lookup($row["symbol"]);

                if($ticker)
                {
                    $count++;

                    printf("<tr>");

                    printf("<td>" . $count . "</td>");
                    printf("<td><a href = \"https://www.google.com/finance?q=" . $ticker["symbol"] . "\" target = \"_BLANK\">" . $ticker["name"] . "</a></td>");
                    printf("<td>" . $ticker["symbol"] . "</td>");
                    printf("<td> $ " . number_format($ticker["price"], 2) . "</td>");
                    printf("<td style = \"text-align:center\">" . $row["num"] . "</td>");
                    
                    printf("</tr>");
                }

            }

        }
    
    ?>
</table>

