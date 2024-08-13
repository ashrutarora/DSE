#!/usr/bin/python3

"""mapper.py"""

import sys

for line in sys.stdin:
   # Remove leading and trailing whitespace
   line = line.strip()

   # Split the line into words
   words = line.split()

   # Emit each word with a count of 1
   for word in words:
       print(f"{word}\t1")  # Use f-strings for cleaner formatting
