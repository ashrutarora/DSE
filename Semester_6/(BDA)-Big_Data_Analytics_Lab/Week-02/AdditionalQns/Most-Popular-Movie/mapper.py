import sys

for line in sys.stdin:
    movie, rating = line.strip().split(',')
    print(f"{rating}\t1")
