<!DOCTYPE html>
<html>
<head>
    <title>Search Employee</title>
    <style>
        table {
            border-collapse: collapse;
            width: 100%;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
        form {
            margin-bottom: 20px;
        }
    </style>
</head>
<body>
    <h1>Search Employee</h1>

    <form action="display_employee.php" method="POST">
        <label for="search">Search by Name:</label>
        <input type="text" id="search" name="search">
        <input type="submit" value="Search">
    </form>
</body>
</html>
