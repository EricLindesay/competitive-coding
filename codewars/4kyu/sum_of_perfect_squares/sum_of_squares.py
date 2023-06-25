#https://www.codewars.com/kata/5a3af5b1ee1aaeabfe000084/train/python

import math


def sum_of_squares(n):
    ans = []
    while n > 0:
        root_floor = math.floor(n**0.5)
        ans.append(root_floor)
        n -= root_floor ** 2
    return len(ans)


if __name__ == "__main__":
    print(sum_of_squares(18)) # 4