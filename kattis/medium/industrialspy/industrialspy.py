import math
from itertools import combinations, permutations


def is_prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if (n % i) == 0:
            return False
    return True


n = int(input())

while n > 0:
    n -= 1

    num = input()
    output = 0
    for i in range(1, len(num)+1):
        numbers = [int(''.join(combo)) for combo in permutations(num, i)]
        for combo in set(numbers):
            print(combo)
            if is_prime(combo):
                output += 1
    print(output)
