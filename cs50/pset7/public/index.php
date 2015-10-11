<?php

    // configuration
    require("../includes/config.php"); 

    $id = $_SESSION["id"];
    $portfolio = query("SELECT * FROM portfolio WHERE id = ?", $id);
    $user = query("SELECT * FROM users WHERE id = ?", $id);
    
    $positions = [];
    foreach($portfolio as $holding)
    {
        $stock = lookup($holding["symbol"]);
        if($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $holding["shares"],
                "symbol" => $stock["symbol"],
                "purchase_price" => $holding["price"]
            ];
        }
    }
    
    render("portfolio.php", ["data" => $positions, "user" => $user, "title" => "Portfolio"]);
    
?>
