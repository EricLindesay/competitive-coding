#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // find the duplicates first
		map<char, int> duplicates;  // stores how many duplicates of the character there is
		map<char, bool> seen;
		for (char &c : s) {
			if (seen.count(c)) {
				if (duplicates.count(c)) {
					duplicates[c]++;
				} else {
					duplicates[c] = 1;
				}
			} else {
				seen[c] = 1;
			}
		}

		// go though each duplicated character position. Work out how good removing the character there will be.
		// If removing the character is always better, do it. Otherwise, store the difference between the current character and the next one along. Then remove the smallest of these differences in a third for loop. O(3n)
		map<char, vector<int>> differences;
		vector<bool> remove(s.length(), false);
		for (char &c : s) {
			if (duplicates.count(c) && duplicates[c] > 0) {
			}
		}
		cout << endl;
		return "";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().removeDuplicateLetters("bcabc") << endl;
	cout << Solution().removeDuplicateLetters("cbacdcbc") << endl;

    return 0;
}
