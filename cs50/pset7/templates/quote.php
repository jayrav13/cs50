<div class="form-group" name = "quote">
    <?php 
    
    if (isset($name) && isset($symbol) && isset($price))
    {
        printf("<b><a href = \"https://www.google.com/finance?q=". $symbol . "\" target = \"_BLANK\">" . $name . "</a></b>" . " <br />(" . $symbol . ")<br />Last Stock Price: $" . number_format($price, 2));
    ?>
        <br /><br />
        <form action="buy_confirm.php" method="post">
            <fieldset>  
                <div class="form-group">
                    <input class="form-control" readonly placeholder = "Stock Ticker" style = "text-align:center" name="ticker" type="text" value = <?php echo $symbol; ?> />
                </div>
                <div class="form-group">
                    <input autofocus class="form-control" autocomplete = "off" name="shares" style = "text-align:center" placeholder="No. Shares" type="text"/>
                </div>
                <div class="form-group">
                    <button name = "search" type="submit" class="btn btn-default">Buy Shares</button>
                </div>
            </fieldset>
        </form>
        <br />

    <?php
        }
        else
        {
            printf("Stock not found - try again!");
            ?>
            <br /><br />
            <?php
        }
        
    ?>
    <a href="javascript:history.go(-1);">Back</a>
</div>
