<?php
$potvrda = 1;
$id = $_GET["id"];

shell_exec ("/var/www/html/pwmled.py $id 99 00");

echo json_encode(array("potvrda" => $potvrda));
?>
