class Solution:
    def findRepeatedDnaSequences(self, s: str) -> list[str]:
        map = {}
        repeats = []

        if len(s) < 10:
            return []

        for i in range(10, len(s) + 1):
            if map.get(s[i-10:i], None):
                map[s[i-10:i]] += 1
                if map[s[i-10:i]] == 2:
                    repeats.append(s[i-10:i])
            else:
                map[s[i-10:i]] = 1

        return repeats


# https://leetcode.com/problems/repeated-dna-sequences/submissions/977179877/
print(Solution().findRepeatedDnaSequences("AAAAAAAAAAA"))
