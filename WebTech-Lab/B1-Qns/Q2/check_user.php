<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];

    // Read user data from JSON file
    $users = json_decode(file_get_contents('users.json'), true);

    $foundUser = null;
    foreach ($users as $user) {
        if (strtolower($user['name']) === strtolower($name)) {
            $foundUser = $user;
            break;
        }
    }

    if ($foundUser) {
        // Return the details of the found user 
        echo "<h2>User Details Found</h2>";
        echo "<p>Name: " . $foundUser['name'] . "</p>";
        echo "<p>Email: " . $foundUser['email'] . "</p>";
        echo "<p>Phone: " . $foundUser['phone'] . "</p>";
        echo "<p>Class: " . $foundUser['class'] . "</p>";


    } else {
        echo "<p>No user found with the name '$name'</p>";
    }
}
?>