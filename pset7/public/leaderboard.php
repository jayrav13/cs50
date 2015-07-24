<?php

    // configuration
    require("../includes/config.php"); 

    // SQL queries
    $data = query("SELECT history_count.id, history_count.username, history_count.date, history_count.cash, history_count.historyCount, COUNT(portfolio.id) as portfolioCount FROM (SELECT users.id, users.username, users.date, users.cash, COUNT(history.id) as historyCount FROM users LEFT JOIN history ON users.id = history.id GROUP BY username) as history_count LEFT JOIN portfolio ON history_count.id = portfolio.id GROUP BY history_count.username");
    $portfolio = query("SELECT * FROM portfolio");
    $users = query("SELECT * FROM users");

    // declares totals array, assigns all user id values to 0
    $totals = [];

    foreach($users as $user)
    {
        $totals[$user["id"]] = $user["cash"];
    }

    foreach($portfolio as $tickers)
    {
    	$totals[$tickers["id"]] = $totals[$tickers["id"]] + calculateCost($tickers["symbol"], $tickers["shares"]);
    }

    render("leaderboard.php", ["data" => $data, "users" => $users, "portfolio" => $portfolio, "totals" => $totals, "title" => "Leaderboard"]);
    
?>
