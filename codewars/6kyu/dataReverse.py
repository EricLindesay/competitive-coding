import numpy as np

def data_reverse(data):
    ans = []
    for i in range(0, len(data), 8):
        ans.insert(0, data[i:i+8])
    return [y for x in ans for y in x]


print(data_reverse([1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0]))
