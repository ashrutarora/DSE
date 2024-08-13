<?php
session_start();

// Check if the session variable for page views exists, if not, initialize it to 0
if (!isset($_SESSION['page_views'])) {
    $_SESSION['page_views'] = 0;
}

// Increment page views count on each refresh
$_SESSION['page_views']++;

// Display the page views count on the web page
echo "Page views: " . $_SESSION['page_views'];
?>