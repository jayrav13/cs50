<!DOCTYPE html>

<html>

    <head>
        <link rel="shortcut icon" href="/favicon.ico"/>

        <link href="/css/bootstrap.min.css" rel="stylesheet"/>
        <link href="/css/bootstrap-theme.min.css" rel="stylesheet"/>
        <link href="/css/styles.css" rel="stylesheet"/>

        <?php if (isset($title)): ?>
            <title>C$50 Finance: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>C$50 Finance</title>
        <?php endif ?>

        <script src="/js/jquery-1.11.1.min.js"></script>
        <script src="/js/bootstrap.min.js"></script>
        <script src="/js/scripts.js"></script>

    </head>

    <body>

        <div class="container">

            <div id="top">
                <a href="/"><img alt="C$50 Finance" src="/img/logo.gif"/></a>
            </div>
            
            <div style = "margin:auto">
                <div style = "margin:auto;width:680px">
                    <ul class="nav nav-pills">
                        <li><a href="index.php">Portfolio</a></li>
                        <li><a href="quote.php">Buy</a></li>
                        <li><a href="sell.php">Sell</a></li>
                        <li><a href="history.php">History</a></li>
                        <li><a href="updates.php">Updates</a></li>
                        <li><a href="leaderboard.php">Leaderboard</a></li>
                        <li><a href="frequent.php">What's Hot?</a></li>
                        <li><a href="logout.php"><strong>Log Out</strong></a></li>
                    </ul>
                </div>
            </div>
            <h2><?php if(isset($title)){echo $title;} ?></h2><br />
            <div id="middle">
                
