<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $phone = $_POST['phone'];
    $address = $_POST['address'];
    $password = $_POST['password'];
    $confirmPassword = $_POST['confirm_password'];

    // Validate if passwords match
    if ($password === $confirmPassword) {
        // Storing values in an associative array
        $userDetails = array(
            "name" => $name,
            "email" => $email,
            "phone" => $phone,
            "address" => $address,
            "password" => $password
        );

        // Convert array to JSON and store in a file (You can change the file path)
        $file = 'user_data.json';
        $json = json_encode($userDetails, JSON_PRETTY_PRINT);
        file_put_contents($file, $json);

        echo "Registration successful!";
    } else {
        echo "Passwords do not match!";
    }
}
?>