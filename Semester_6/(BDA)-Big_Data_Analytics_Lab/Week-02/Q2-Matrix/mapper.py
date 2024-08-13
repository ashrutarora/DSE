#!/usr/bin/python3
import sys

#cache_info = open("cache.txt").readLines()[0].split(",")
row_a, col_b = 3,3

for line in sys.stdin:
        matrix_index, row, col, value = line.rstrip().split(",")
        if matrix_index == "a":
                        key = row + "," + col
                        print ("%s\t%s\t%s"%(matrix_index,key,value))

        else:
                        key = row + "," + col
                        print ("%s\t%s\t%s"%(matrix_index,key,value))
