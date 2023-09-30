from itertools import combinations
import math

t = int(input())
for i in range(0, t):
    n = int(input())

    max_val = math.factorial(n)
    types = {}
    duplicates = []
    for i in range(0, n):
        inp = input().split(" ")[1]
        if inp in types.keys():
            types[inp] += 1
            duplicates.append(inp)
        else:
            types[inp] = 1

    count = max_val
    for dupe in duplicates:
        count -= types[dupe]
    print(count)
