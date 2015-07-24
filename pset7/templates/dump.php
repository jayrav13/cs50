<!DOCTYPE html>

<html>

    <head>
        <title>dump</title>
    </head>

    <body>
        <pre>

        <?php 
        	extract($variables);

    		foreach($variables as $variable)
    		{
    			print_r($variable); 
			}
        ?>

        </pre>
    </body>

</html>
