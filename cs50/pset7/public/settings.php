<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        $data = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        render("settings_form.php", ["data" => $data, "title" => "Settings"]);
    }
    elseif ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $data = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    	if(strlen($_POST["password"]) > 0 || strlen($_POST["confirmation"] > 0))
        {
            if(($_POST["password"] == $_POST["confirmation"]))
            {
                if(strlen($_POST["password"]) >= 8)
                {
                    query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["password"]), $_SESSION["id"]);
                }
                else
                {
                    apologize("Passwords must be at least 8 characters long!");
                }
            }
            else
            {
                apologize("Passwords do not match!");
            }
        }

        if(strlen($_POST["email"]) > 0  && $_POST["email"] != $data[0]["email"])
        {
            query("UPDATE users SET email = ? WHERE id = ?", $_POST["email"], $_SESSION["id"]);
        }
        redirect("/");

    }

?>
