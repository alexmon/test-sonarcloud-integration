<?php
// Get the message from the URL parameters (user input)
$message = $_GET['message'];

// Display the message directly, vulnerable to XSS
echo "User message: " . $message;
?>
