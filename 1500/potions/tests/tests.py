import random

with open("testfile", "w") as f:
    for i in range(0,1000):
        n = random.randint(2000, 2000)
        arr = [str(random.randint(-1000,1000)) for x in range(n)]
        
        f.write(str(n) + "\n" + ' '.join(arr)+"\n-----\n")