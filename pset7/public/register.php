<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $user = query("SELECT * FROM users WHERE username = ?", $_POST["username"]);
        $email = query("SELECT * FROM users WHERE email = ?", $_POST["email"]);

        // TODO
        if(strlen($_POST["email"]) == 0)
        {
            apologize("Missing email address!");
        }
        elseif(strlen($_POST["username"]) == 0)
        {
            apologize("Missing username!");
        }
        elseif(strlen($_POST["password"]) == 0 || strlen($_POST["confirmation"]) == 0)
        {
            apologize("Missing password field!");
        }
        elseif($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Passwords do not match!");
        }
        elseif(strlen($_POST["password"]) < 8)
        {
            apologize("Passwords must be at least 8 characters long!");
        }
        elseif($user)
        {
            apologize($_POST["username"] . " is already registered!");
        }
        elseif($email)
        {
            apologize($_POST["email"] . " is already registered!");
        }
        else
        {
            $result = query("INSERT INTO users (username, hash, cash, email) VALUES(?, ?, 10000.00, ?)", $_POST["username"], crypt($_POST["password"]), $_POST["email"]);
            if($result !== false)
            {
                $rows = query("SELECT LAST_INSERT_ID() as id");
                $_SESSION["id"] = $rows[0]["id"];
                welcomeEmail(["email" => $_POST["email"], "username" => $_POST["username"]]);
                redirect("/");
            }
        }

    }

?>
