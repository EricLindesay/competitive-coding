import random

with open("testfile", 'a') as f:
    for i in range(50):
        f.write(f"\n{random.randint(20, 65)}|{random.randint(2, 9)}")