<table class = "table table-striped" style = "text-align:left" width = 500>
    <thead><tr><th>Rank</th><th>Username</th><th>Date Joined</th><th>Current Holdings</th><th>Total Trades</th><th>Buying Power</th><th>Invested Funds</th><th>Portfolio Value</th></tr></thead>
    
    <?php

        if(isset($data) && isset($users) && isset($portfolio) && isset($totals))
        {
            for($i = 0; $i < count($data); $i++)
            {
                $data[$i]["value"] = $totals[$data[$i]["id"]];
            }

            array_sort_by_column($data, 'value');
            $count = 0;

        	foreach($data as $row)
        	{     

        		printf("<tr>");
                
                $count++;

                printf("<td>" . $count . "</td>");
        		printf("<td>" . $row["username"]. "</td>");
        		printf("<td>" . $row["date"] . "</td>");
        		printf("<td>" . $row["portfolioCount"] . "</td>");
        		printf("<td>" . $row["historyCount"] . "</td>");
                printf("<td> $ " . number_format($row["cash"], 2) . "</td>");
                printf("<td> $ " . number_format($row["value"] - $row["cash"], 2) . "</td>");
                printf("<td> $ " . number_format($row["value"], 2) . "</td>");

        		printf("</tr>");
        	}
        }
    
    ?>
</table>

