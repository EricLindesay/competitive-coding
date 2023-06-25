class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        count = 0
        string = str(num)
        for i in range(len(string) - k + 1):
            chars = string[i:i+k]
            if int(chars) == 0:
                continue
            if num % int(chars) == 0:
                count += 1
        return count


print(Solution().divisorSubstrings(430043, 2))
