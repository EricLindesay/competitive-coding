import random

with open("testfile", 'a') as f:
    for i in range(50):
        digs = random.randint(2, 6)
        f.write(f"\n{random.randint(digs, digs*9)}|{digs}")
