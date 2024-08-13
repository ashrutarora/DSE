<!DOCTYPE html>
<html>
<head>
    <title>Employee Details</title>
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
    </style>
</head>
<body>
    <h1>Employee Details</h1>

    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Position</th>
                <th>Department</th>
            </tr>
        </thead>
        <tbody>
            <?php
            if ($_SERVER["REQUEST_METHOD"] == "POST") {
                $searchValue = $_POST['search'];

                // Read JSON file containing employee details
                $jsonString = file_get_contents('employees.json');
                $employees = json_decode($jsonString, true);

                // Search for the employee based on the entered name
                foreach ($employees as $employee) {
                    if (stripos($employee['name'], $searchValue) !== false) {
                        echo "<tr>";
                        echo "<td>" . $employee['id'] . "</td>";
                        echo "<td>" . $employee['name'] . "</td>";
                        echo "<td>" . $employee['position'] . "</td>";
                        echo "<td>" . $employee['department'] . "</td>";
                        echo "</tr>";
                    }
                }
            }
            ?>
        </tbody>
    </table>
</body>
</html>
