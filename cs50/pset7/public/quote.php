<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET" && !isset($_GET["quote"]))
    {
        // else render form
        render("quote_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET["quote"]))
    {
        // TODO
        $result = lookup($_GET["quote"]);
        if($result["name"] == "N/A")
        {
            apologize("Invalid ticker!");
        }
        else
        {
            render("quote.php", ["title" => "Buy", "symbol" => $result["symbol"], "name" => $result["name"], "price" => $result["price"]]);
        }
    }

?>
