<?php


    require_once 'smsc.php';    
	
    list($sms_id, $sms_cnt, $cost, $balance) = send_sms("37368094006", "It's a test.", 1);
    
    $success = $sms_cnt>=0;
	
	var_dump($success);