from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join([k[0]*k[1] for k in Counter(s).most_common()])

        # c = Counter(s)
        # ret = ""
        # for k in c.most_common():
        #     ret += k[0] * k[1]
        # return ret


print(Solution().frequencySort("tree"))
print(Solution().frequencySort("cccaaa"))
print(Solution().frequencySort("Aabb"))
