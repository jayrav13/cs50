<?php
    if(isset($portfolio))
    {
        if(empty($portfolio))
        {
            printf("Your portfolio is empty! Go <a href = \"quote.php\">buy stocks</a> and build your portfolio now!");
        }
        else
        {
?>
<form method="post" action="sell-confirm.php"> <!--action="sell-confirm.php" -->
    <fieldset> 
        <div class="form-group"> 
            <select class = "form-control" name = "sellStock">
                <?php
                    if(isset($portfolio))
                    {
                        foreach($portfolio as $item)
                        {
                            printf("<option style=\"width:200px;text-align:center\" value = " . $item["symbol"] . ">");
                            $ticker = lookup($item["symbol"]);
                            printf($ticker["name"] . " (" . $ticker["symbol"] . ")");
                            printf("</option>");
                        }
                    }
                ?>
            </select>
        </div>
        <div class="form-group">
            <input class="form-control" style = "text-align:center" align = "center" autocomplete = "off" name="sellShares" placeholder="Shares" />
        </div>
        <div class = "form-group">
            <p id = "calculation"></p>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Sell Shares</button>
        </div>
    </fieldset>
</form>
<?php
        }
    }
?>


