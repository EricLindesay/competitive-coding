#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> seen;
        int left = 0;
        int right = 0;
        int longest = 0;

        for (int i = 0; i < s.length(); i++) {
			auto it = seen.find(s[i]);
            if (it != seen.end()) {
                // You've found it in the thing
				if (seen[s[i]] == 0) { // if the number of occurances for this character is zero, just increment the number of occurances.
					seen[s[i]] = 1;	
				} else {  // otherwise it is a repeat character so we need to watch out.
					// loop through the string, starting from the left pointer up until you
					// find a character which is the same as the current one. Make sure to decrement
					// the occurance map for each of the characters you see along the way.
					printf("Found duplicate: %c\n", s[i]);
					while (s[left] != s[i]) {
						seen[s[left]] = seen[s[left]] - 1;  // decrement the number of occurances of the character
						cout << "Decrement " << s[left] << " to " << seen[s[left]] << endl;
						left++; // increment left pointer
					}
					// now they are equal, so step along once more and do the decrease
					seen[s[left]] = 1;
					left++;
				}
			} else {
				// its not in the map yet, add it to the map with value 1
				seen[s[i]] = 1;
			}
			right++;
			longest = max(longest, right-left);
			cout << s.substr(left, right+1) << endl;
        }

        return longest;
    }
};

int main()
{
    cout << Solution().lengthOfLongestSubstring("tmmzuxt") << endl;
}
