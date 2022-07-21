import random

with open("manual", "w") as f:
    a = 200000
    b = 200000
    f.write(f"{a} {b}\n")
    str1 = ""
    for i in range(a):
        str1 += str(random.randint(1, a))+" "
    f.write(str1+"\n")

    for i in range(b):
        n1 = random.randint(1, b)
        n2 = random.randint(n1, b)
        f.write(f"{n1} {n2}\n")