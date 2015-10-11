<form action="register.php" method="post" autocomplete = "off">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="username" placeholder="Username" type="text"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="password" placeholder="Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Confirm Password" type="password"/>
        </div>
        <div class="form-group">
            <input autofocus class="form-control" name="email" placeholder="Email" type="text"/>
        </div>
        <div class = "form-group" style = "font-size:10px"><b>Why include an email address?</b><br />We send email receipts when you place trades. Be sure to enter a valid email address so you can take advantage of this functionality!</div>

        <div class="form-group">
            <button type="submit" class="btn btn-default">Register</button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="login.php">login</a>
</div>
