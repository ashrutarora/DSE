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
        form {
            margin-bottom: 20px;
        }
    </style>
</head>
<body>
    <h1>Employee Details</h1>

    <form method="post">
        <label for="id">ID:</label>
        <input type="text" id="id" name="id"><br><br>
        
        <label for="name">Name:</label>
        <input type="text" id="name" name="name"><br><br>
        
        <label for="position">Position:</label>
        <input type="text" id="position" name="position"><br><br>
        
        <label for="department">Department:</label>
        <input type="text" id="department" name="department"><br><br>
        
        <input type="submit" value="Add Employee">
    </form>

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
            // Read existing JSON data
            $jsonString = file_get_contents('employees.json');
            $employees = json_decode($jsonString, true);

            if ($_SERVER["REQUEST_METHOD"] == "POST") {
                // Retrieve form data
                $newEmployee = [
                    'id' => $_POST['id'],
                    'name' => $_POST['name'],
                    'position' => $_POST['position'],
                    'department' => $_POST['department']
                ];

                // Add new employee to the existing array
                $employees[] = $newEmployee;

                // Save updated data back to the JSON file
                file_put_contents('employees.json', json_encode($employees, JSON_PRETTY_PRINT));

                // Display all employees
                foreach ($employees as $employee) {
                    echo "<tr>";
                    echo "<td>" . $employee['id'] . "</td>";
                    echo "<td>" . $employee['name'] . "</td>";
                    echo "<td>" . $employee['position'] . "</td>";
                    echo "<td>" . $employee['department'] . "</td>";
                    echo "</tr>";
                }
            }
            ?>
        </tbody>
    </table>
</body>
</html>
