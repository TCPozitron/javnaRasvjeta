<?php

$id = $_GET["id"];
$value = $_GET["regulationValue"];
$time = $_GET["regulationTime"];

system ("/usr/bin/java -jar /var/www/html/pwmled.jar $id $value $time");


?>