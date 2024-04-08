import re

t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    s = input()

    s = re.sub("mapie", "maie", s)
    s = re.sub("map", "mp", s)
    s = re.sub("pie", "pe", s)
    print(f"{n-len(s)}")