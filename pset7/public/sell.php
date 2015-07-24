<?php

    // configuration
    require("../includes/config.php"); 

    $id = $_SESSION["id"];
    $portfolio = query("SELECT * FROM portfolio WHERE id = ?", $id);
    $user = query("SELECT * FROM users WHERE id = ?", $id);
    
    render("sell_form.php", ["title" => "Sell", "portfolio" => $portfolio, "user" => $user]);
    
?>
