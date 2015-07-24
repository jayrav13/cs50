<?php

    // configuration
    require("../includes/config.php"); 
    
    $id = $_SESSION["id"];
    $stock = $_POST["sellStock"];
    $shares = $_POST["sellShares"];
    
    $portfolio = query("SELECT * FROM portfolio WHERE id = ? and SYMBOL = ?", $id, $stock);
    $user = query("SELECT * FROM users WHERE id = ?", $id);
    $current = lookup($stock);
    

    if(!is_numeric($shares))
    {
        apologize("Non-numeric entry - try again!");
    }
    elseif($shares <= 0)
    {
        apologize("Your entry is less than or equal to 0!");
    }
    elseif($shares > $portfolio[0]["shares"])
    {
        apologize("You're trying to sell more shares than you own!");
    }
    elseif($shares != intval($shares))
    {
        apologize("You may have entered a non-integer value!");
    }
    else
    {
        $total_price = $current["price"] * $shares;
        
        if($shares == $portfolio[0]["shares"])
        {
            query("DELETE FROM portfolio WHERE id = ? and symbol = ?", $id, $stock);
        }
        else
        {
            query("UPDATE portfolio SET shares = shares - ? WHERE id = ? AND symbol = ?", $shares, $id, $stock);
        }
        query("UPDATE users SET cash = cash + ? WHERE id = ?", $total_price, $id);
        query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)", $id, "SELL", $current["symbol"], $shares, $current["price"]);

        orderEmail(["transaction" => "SELL", "email" => $user[0]["email"], "username" => $user[0]["username"], "company" => $current["name"], "ticker" => $current["symbol"], "shares" => $shares, "price" => $current["price"]]);

        redirect("index.php");
    }

?>
