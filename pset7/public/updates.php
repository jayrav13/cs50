<?php

    // configuration
    require("../includes/config.php"); 

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
	    $id = $_SESSION["id"];
	    $updates = query("SELECT * FROM updates ORDER BY date DESC");
	    $user = query("SELECT * FROM users WHERE id = ?", $id);
	    
	    render("updates.php", ["updates" => $updates, "user" => $user, "title" => "Updates"]);    	
    }
    elseif ($_SERVER["REQUEST_METHOD"] == "POST")
    {
	    $text = $_POST["text"];

	    if(strlen($text) > 140)
	    {
	    	apologize("Text is " . strlen($text) . " characters long. Max length is 140!");
		}
		else
		{
	        $user = query("SELECT username FROM users WHERE id = ?", $_SESSION["id"]);
	    	query("INSERT INTO updates (text, username) VALUES(?, ?)", $text, $user[0]["username"]);
		}

	    redirect("updates.php");
    }
    
?>
