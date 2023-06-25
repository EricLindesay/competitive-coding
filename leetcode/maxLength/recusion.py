import itertools
from collections import Counter

def repeats(arr):
    c = Counter(''.join(arr))
    for i in c.values():
        if i > 1:
            return 0
    
    return len(c)

class Solution:
    def maxLength(self, arr: list[str]) -> int:
        maxLen = 0
        for i in range(0, len(arr)+1):
            for j in itertools.combinations(arr, i):
                # look for any repeat characters
                maxLen = max(maxLen, repeats(j))
        return maxLen



if __name__ == "__main__":
    s = Solution()
    arr = ["un", "iq", "ue"]
    print(s.maxLength(arr))
