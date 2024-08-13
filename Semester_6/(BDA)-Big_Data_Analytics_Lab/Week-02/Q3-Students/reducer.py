#!/usr/bin/python3

import sys

# Read all lines from the input
lines = sys.stdin.readlines()

# Sort lines based on the student name (using the first field after splitting by '\t')
sorted_lines = sorted(lines, key=lambda x: x.strip().split('\t')[0])

# Output the sorted lines
for line in sorted_lines:
    print(line.strip())
