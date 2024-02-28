#!/usr/bin/python3

import sys

for line in sys.stdin:
    # Remove leading and trailing whitespaces, and split the line into fields
    fields = line.strip().split(',')
    
    # Extract student name and emit it as the key along with the rest of the details as the value
    print(f'{fields[1]}\t{line.strip()}')
