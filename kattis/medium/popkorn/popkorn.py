
n = int(input())
output = 4;
groupSize = n/4;
perGroup = 0.5 * groupSize * (groupSize - 1)
output += perGroup * 4
print(int(output))
