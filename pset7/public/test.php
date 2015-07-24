<?php

	require("../includes/config.php");

	if(isset($_SESSION["id"]))
	{
		$data = query("SELECT admin FROM users WHERE id = ?", $_SESSION["id"]);
		if($data[0]["admin"] != 1)
		{
			redirect("/");
		}
		else
		{
			$data = [];
			if(isset($_GET["search_id"]))
			{
				$data = query("SELECT * FROM users WHERE id = ?", $_GET["search_id"]);
			}
			else
			{
				$data = query("SELECT * FROM users");
			}
			
			foreach($data as $row)
			{
				printf($row["date"] . " - MD5: " . md5($row["date"]) . " - CRYPT: " . crypt($row["date"]) . "<br />");
			}
		}
	}


?>