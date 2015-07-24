<?php 

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        redirect("/");
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        // look for quote, pull user data
        $ticker = lookup($_POST["ticker"]);
        $user = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        
        // if lookup returned nothing, apologize
        if($ticker === FALSE)
        {
            apologize("Ticker not found - please try again!");
        }
        
        // if the shares field is not numeric, apologize
        if(!is_numeric($_POST["shares"]))
        {
           apologize("Please enter an integer value for number of shares!"); 
        }
        
        // else, convert shares to integer value
        $shares = intval($_POST["shares"]);

        // at this point, if $shares != $_POST["shares"], that means that
        // the user entered a decimal value, do not allow and apologize.
        if($shares != $_POST["shares"])
        {
            apologize("Please enter an integer value for number of shares!"); 
        }
        
        if($shares * $ticker["price"] > $user[0]["cash"])
        {
            apologize("You don't have enough funds!");
        }
        
        // purchase
        if($_SESSION["id"] == 53)
        {
            query("INSERT INTO portfolio (id, symbol, shares, price) VALUES(?, ?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $user[0]["id"], $ticker["symbol"], $shares, $ticker["price"]);
        }
        else
        {
            query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $user[0]["id"], $ticker["symbol"], $shares);
        }
        query("UPDATE users SET cash = cash - ? WHERE id = ?", $shares * $ticker["price"], $user[0]["id"]);
        query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)", $user[0]["id"], "BUY", $ticker["symbol"], $shares, $ticker["price"]);

        orderEmail(["transaction" => "BUY", "email" => $user[0]["email"], "username" => $user[0]["username"], "company" => $ticker["name"], "ticker" => $ticker["symbol"], "shares" => $shares, "price" =>$ticker["price"]]);

        redirect("/");
    }
    
?>
