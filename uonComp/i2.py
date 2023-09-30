from itertools import combinations

t = int(input())
for i in range(0, t):
    n = int(input())

    types = {}
    all_things = []
    for i in range(0, n):
        inp = input().split(" ")[1]
        types[inp] = types.get(inp, 0) + 1

    unique = types.keys()

    count = n
    prod = 1
    for x in unique:
        prod *= types[x]

    if len(unique) >= 2:
        count += prod

    print(count)
