<?php

$id = $_GET["id"];

system ("/usr/bin/java -jar /var/www/html/pwmled.jar $id 0 500");


?>