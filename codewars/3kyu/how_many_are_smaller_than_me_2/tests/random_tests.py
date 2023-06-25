import random

with open("testfile", 'a') as f:
    for _ in range(50):
        arr = []
        for i in range(50):
            arr.append(random.randint(0, 100))

        f.write(f"\n{str(arr)}")
