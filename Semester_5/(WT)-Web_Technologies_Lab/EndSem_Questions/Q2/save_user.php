<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $userData = [
        'name' => $_POST['name'],
        'email' => $_POST['email'],
        'phone' => $_POST['phone'],
        'class' => $_POST['class']
    ];

    // Read existing user data from JSON file
    $existingData = json_decode(file_get_contents('users.json'), true);

    // Add new user data to the existing data
    $existingData[] = $userData;

    // Save updated data back to the JSON file
    file_put_contents('users.json', json_encode($existingData, JSON_PRETTY_PRINT));

    // Display saved user details
    echo "<h2>Saved User Details</h2>";
    echo "<p>Name: " . $userData['name'] . "</p>";
    echo "<p>Email: " . $userData['email'] . "</p>";
    echo "<p>Phone: " . $userData['phone'] . "</p>";
    echo "<p>Class: " . $userData['class'] . "</p>";

    // Include check_user.php to display user details if exists
    include('check_user.php');
}
?>