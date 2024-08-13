#!/usr/bin/python3

import sys

current_unit = None
total_salary = 0
total_employees = 0

for line in sys.stdin:
    # Split the line into fields
    unit, salary = line.strip().split('\t')

    # Convert salary to float
    salary = float(salary)

    # If the unit changes, emit the result for the previous unit
    if current_unit and current_unit != unit:
        average_salary = total_salary / total_employees
        print(f"{current_unit}\t{average_salary}")

        # Reset counters for the new unit
        current_unit = unit
        total_salary = salary
        total_employees = 1
    else:
        # Accumulate salary and employee count for the current unit
        current_unit = unit
        total_salary += salary
        total_employees += 1

# Emit the result for the last unit
if current_unit:
    average_salary = total_salary / total_employees
    print(f"{current_unit}\t{average_salary}")
