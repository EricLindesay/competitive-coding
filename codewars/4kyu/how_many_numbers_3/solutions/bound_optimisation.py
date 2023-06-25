# https://www.codewars.com/kata/5877e7d568909e5ff90017e6/train/python
# still too slow

import math


def find_all(sum_dig, digs):
    if sum_dig > digs * 9:  # it's impossible to reach the number
        return []
    if sum_dig < digs:
        return []

    ans = []
    lower_bound = int("1" * (digs))
    upper_bound = int(str(math.ceil(sum_dig / digs)) * digs)

    print(lower_bound, upper_bound)

    for i in range(lower_bound, upper_bound + 1):
        if digits_ascending(i):
            val = sum(int(x) for x in str(i))
            if val == sum_dig:
                ans.append(i)

    if ans:
        return [len(ans), ans[0], ans[-1]]
    else:
        return []


def digits_ascending(num: int) -> bool:
    return str(num) == "".join(sorted(str(num)))


if __name__ == "__main__":
    print(find_all(40, 7))
