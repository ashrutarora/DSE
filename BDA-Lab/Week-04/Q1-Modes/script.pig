-- Load data from a local text file
data = LOAD 'input_data.txt' USING PigStorage(',') AS (student_id:int, name:chararray, age:int, marks:int);

-- Calculate average marks by age
grouped_data = GROUP data BY age;
average_marks = FOREACH grouped_data GENERATE group AS age, AVG(data.marks) AS avg_marks;

-- Store the result
STORE average_marks INTO 'output_local';
