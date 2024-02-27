#!/usr/bin/python3

"""reducer.py"""

import sys

# Initialize variables outside the loop for efficiency
current_word = None
current_count = 0

for line in sys.stdin:
    # Remove leading and trailing whitespaces
    line = line.strip()

    # Parse the input (word and count)
    word, count = line.split('\t')
    # Convert count to integer
    try:
        count = int(count)
    except ValueError:
        # Ignore lines with invalid count (not integers)
        continue

    # Accumulate count for the current word
    if current_word == word:
        current_count += count
    else:
        # If word changes, emit the previous word and count (if any)
        if current_word:
            print(f"{current_word}\t{current_count}")
        # Update variables for the new word
        current_word = word
        current_count = count

# Print the last word and count (if any)
if current_word:
    print(f"{current_word}\t{current_count}")
