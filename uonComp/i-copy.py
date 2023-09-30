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

    count = n;
    for x in range(2, len(unique)+1):
        for combo in combinations(unique, x):
            print(combo)
            temp_sum = 1
            for y in combo:
                temp_sum *= types[y]
            count += temp_sum
    print(count)
