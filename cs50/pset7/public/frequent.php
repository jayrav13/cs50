<?php

    // configuration
    require("../includes/config.php"); 

    // SQL queries
    $data = query("SELECT symbol, COUNT(symbol) as num FROM history GROUP BY symbol ORDER BY num DESC LIMIT 10");

    render("frequent.php", ["data" => $data, "title" => "What's Hot?"]);
    
?>
