<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("invitation_form.php", ["title" => "Invite"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $email = $_POST["invite-email"];
        
        if(!filter_var($email, FILTER_VALIDATE_EMAIL))
        {
            apologize("Invalid email address - please enter a valid email.");
        }
        else
        {
            $self = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
            $data = query("SELECT * FROM invite WHERE id = ? AND email = ?", $_SESSION["id"], $email);
            $users = query("SELECT COUNT(email) AS count FROM users WHERE email = ?", $email);

            if($users[0]["count"] > 0)
            {
                apologize("This email address is already registered under a user!");
            }
            elseif(count($data) > 0)
            {
                apologize("You've already invited this user!");
            }
            else
            {
                query("INSERT INTO invite VALUES (?, ?)", $_SESSION["id"], $email);
                inviteEmail(["username" => $self[0]["username"], "id" => $self[0]["id"], "email" => $email]);
                redirect("/");
            }


        }
    }

?>
