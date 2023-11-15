<?php
// Set the timezone
date_default_timezone_set('Your/Timezone'); // Replace 'Your/Timezone' with the desired timezone

// Function to generate the current date-time
function getCurrentDateTime() {
    return date('Y-m-d H:i:s');
}

// Check if the 'last_visited' cookie is set
if(isset($_COOKIE['last_visited'])) {
    $lastVisited = $_COOKIE['last_visited'];
    echo "Last visited on: $lastVisited";
} else {
    echo "First time visiting!";
}

// Store current date-time in a cookie named 'last_visited' for one week (adjust as needed)
$expiryTime = time() + (7 * 24 * 60 * 60); // One week from now
setcookie('last_visited', getCurrentDateTime(), $expiryTime, '/');
?>
