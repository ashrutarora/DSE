<?php

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_FILES["resume"])) {
    $targetDirectory = "uploads/";
    $targetFile = $targetDirectory . basename($_FILES["resume"]["name"]);
    $fileType = strtolower(pathinfo($targetFile, PATHINFO_EXTENSION));

    // Check if the file is a PDF
    if ($fileType != "pdf") {
        echo "Only PDF files are allowed.";
    } else {
        // Try to upload the file
        if (move_uploaded_file($_FILES["resume"]["tmp_name"], $targetFile)) {
            echo "The resume file has been uploaded successfully.";
        } else {
            echo "Sorry, there was an error uploading your file.";
        }
    }
}
?>
