            </div>

            <div id="bottom">
            	<?php
            		if(isset($_SESSION["id"]))
            		{
            			$total = 0;

            			$portfolio = query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);
            			$user = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);

            			foreach($portfolio as $row)
            			{
            				$ticker = lookup($row["symbol"]);
            				$total = $total + ($row["shares"] * $ticker["price"]);
            			}
            			printf("<table width = 300 align = center><tr><td align = left>Logged in as:</td><td><b>" . $user[0]["username"] . "</b> | <a href = \"settings.php\">Settings</a></td></tr><tr><td align = left>Total Portfolio Value:</td><td><b>$ " . number_format(($total + $user[0]["cash"]), 2) . "</b></td></tr><tr><td align = left>Total Buying Power:</td><td><b>$ " . number_format($user[0]["cash"], 2) . "</b></td></tr></table>");
            		}
            	?>
                <br />
                Copyright &#169; <a href = "http://www.cs50.harvard.edu/" target = "_BLANK">Harvard CS50</a>
            </div>

        </div>

    </body>

</html>
