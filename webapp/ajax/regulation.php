<?php

$id = $_GET["id"];
$value = $_GET["regulationValue"];
$time = $_GET["regulationTime"];

system ("/var/www/html/pwmled.py $id $value $time");


?>
