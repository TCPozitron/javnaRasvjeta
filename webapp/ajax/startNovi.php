<?php
$potvrda = 1;

shell_exec("python /var/www/html/mqttTest.py 10 20 30 2>&1");
echo json_encode(array("potvrda" => $potvrda));
?>
