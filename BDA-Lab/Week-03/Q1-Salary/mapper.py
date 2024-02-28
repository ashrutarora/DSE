#!/usr/bin/python3

import sys

for line in sys.stdin:
    # Split the line into fields
    fields = line.strip().split()

    # Ensure the line has the expected number of fields
    if len(fields) >= 5:
        unit = fields[2]  # Adjust index based on the actual order in your data
        salary = float(fields[4])  # Adjust index based on the actual order in your data
        print(f"{unit}\t{salary}")
