import sys

for line in sys.stdin:
    # Assuming the format is date, temperature
    date, temperature = line.strip().split(',')
    month = date.split('/')[1]
    print(f"{month}\t{temperature}")
