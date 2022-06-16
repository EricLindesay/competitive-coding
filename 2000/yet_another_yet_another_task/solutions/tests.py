import random

with open("f.txt", "w") as f:
    f.write("100000\n")
    for i in range(100000):
        f.write("0 ")
