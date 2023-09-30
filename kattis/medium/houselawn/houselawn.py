import math

l, m = input().split(" ")
l = int(l)
m = int(m)

names = []
price = 100001
for i in range(m):
    name, p, c, t, r = input().split(",")
    p = int(p)
    c = int(c)
    t = int(t)
    r = int(r)

    cutting_time = l / c
    recharge_per_min_cutting = r / t

    time = cutting_time + (recharge_per_min_cutting * cutting_time)

    if time <= 10080:
        if p < price:
            names = [name]
            price = p
        elif p == price:
            names.append(name)

if len(names) == 0:
    print("no such mower")

for name in names:
    print(name)


