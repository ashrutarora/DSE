#!/usr/bin/python3

import sys

for line in sys.stdin:
    year, temperature = map(int, line.strip().split())
    print(f"{year}\t{temperature}")