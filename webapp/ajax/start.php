<?php
$potvrda = 1;
$id = $_GET["id"];

shell_exec ("/usr/bin/java -jar /var/www/html/pwmled.jar $id 100 4000");

echo json_encode(array("potvrda" => $potvrda));
?>