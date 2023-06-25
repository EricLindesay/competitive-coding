# https://www.codewars.com/kata/5672682212c8ecf83e000050/train/python
# UNFINISHED

import math

def dbl_linear(n):
    u = [1]
    y = lambda num: num * 2 + 1
    z = lambda num: num * 3 + 1

    while len(u) < n+1:
        y_list = list(map(y, u))
        z_list = list(map(z, u))

        for y_ele in y_list:
            if not y_ele in u:
                u.append(y_ele)
        

        for z_ele in z_list:
            if not z_ele in u:
                u.append(z_ele)

    print(u)
    return sorted(u)[n]


print(dbl_linear(50))
