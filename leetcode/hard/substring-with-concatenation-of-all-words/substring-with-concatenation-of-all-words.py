class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        '''
        Loop through each substring range
        For each substring, divide the substring into len(substring)/len(words[0]) words
        Sort the array containing these words
        See if it equals the input words
        '''
        words.sort()
        output = []

        substring_length = len(words) * len(words[0])
        for i in range(substring_length, len(s) + 1):
            substring = s[i-substring_length:i]
            substring_words = []
            print("--------")
            print(substring)
            # len(words) should appear in the substring, so loop that many times
            for j in range(len(words)):
                lower = j*len(words[0])
                upper = lower+len(words[0])
                # Get the first N characters from the substring and add them to the output array
                substring_words.append(substring[lower:upper])

            substring_words.sort()

            print(substring_words)
            print(words)
            if words == substring_words:
                output.append(i - substring_length)
        return output


# https://leetcode.com/problems/substring-with-concatenation-of-all-words/
print(Solution().findSubstring("barfoothefoobarman", ["foo", "bar"]))
