<?php

    // configuration
    require("../includes/config.php"); 

    $id = $_SESSION["id"];
    $history = query("SELECT * FROM history WHERE id = ? ORDER BY date DESC", $id);
    $user = query("SELECT * FROM users WHERE id = ?", $id);
    
    render("history_form.php", ["history" => $history, "user" => $user, "title" => "History"]);
    
?>
