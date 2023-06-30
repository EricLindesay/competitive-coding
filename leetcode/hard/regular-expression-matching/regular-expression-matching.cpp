#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class Solution {
public:
	bool isStarred(string re, int index) {
		if (index < re.length() - 1) {
			if (re[index+1] == '*') {
				return true;
			}
		}
		return false;
	}

	string simplifyRegex(string re) {
		// Remove repeated stars. a*a* should simplify to a*.
		string ret = "";
		for (int i=0; i<re.length(); i++) {
			if (re[i] == '*') {
				if (ret[ret.size() - 3] == re[i-1] && ret[ret.size() - 2] == '*') {
					ret = ret.substr(0, ret.length()-1); // ignore the character just before the star
				} else {
					ret += re[i];
				}
			} else {
				ret += re[i];
			}
		}
		return ret;
	}

	bool vomit(string re, int regexIndex, char starChar, int numEaten) {
		printf("vomiting %c %c\n", re[regexIndex], starChar);
		while (re[regexIndex] == starChar) {
			// if it is starred, then don't consider it, stop eating
			if (isStarred(re, regexIndex)) {
				break;
			}
			numEaten--;
			if (numEaten < 0) {
				// You got told to eat 4 but there are only 3 available.
				printf("Num eaten, return false\n");
				return false;
			}
			regexIndex++;	
		}
		return true;
	}

    bool isMatch(string s, string re) {
		re = simplifyRegex(re);
		printf("string: %s, Simplified: %s\n", s.c_str(), re.c_str());
        if (s == re || re == ".*")
			return 1;
		
		string currentRe;
		currentRe = re[0];
		int numEaten = 0;
		char starChar = '\0';
		int regexIndex = 0;
		for (int i=0; i < s.length(); i++) {
			if (regexIndex < re.length() - 1) {
				if (isStarred(re, regexIndex)) {
					// the current character is starred
					starChar = re[regexIndex];
					numEaten = 0;
					currentRe = "";
					currentRe += re[regexIndex];
					currentRe += "*";
					regexIndex += 2;  // increment to move past the star
				} else {
					currentRe = re[regexIndex];
				}
			}
			printf("%s | %s | %s\n", s.substr(0, i+1).c_str(), currentRe.c_str(), re.substr(0, regexIndex+1).c_str());
			if (starChar == '\0') {
				if (s[i] != re[regexIndex]) {
					if (!isStarred(re, regexIndex)) {
						printf("Not equal, return false\n");
						return false;
					}
				}
				else {
					regexIndex++;
					if (regexIndex >= re.length() && i < s.length() - 1) {
						printf("Out of regex length, return false\n");
						return false;
					}
					currentRe = re[regexIndex];
				}
			} else if (s[i] == starChar) {
				numEaten++;
			} else {
				// all 'a's have been eaten. Now look at the regex and see if you can vomit them.
				if (!vomit(re, regexIndex, starChar, numEaten)) 
					return false;
				starChar = '\0';
				numEaten = 0;
			}
		}

		printf("%s | %s | %s\n", s.c_str(), currentRe.c_str(), re.substr(0, regexIndex+1).c_str());
		// make sure the rest of the regex matches
	
		// if you can still vomit them, do that and see what happens
		while (re[regexIndex] == starChar) {
			printf("Vomit: %c %d\n", starChar, numEaten);
			if (isStarred(re, regexIndex)) {
				printf("Regex is starred so break the vomit\n");
				break;
			}
			numEaten--;
			if (numEaten < 0) {
				printf("Outside for loop, num eaten false\n");
				return false;
			}
			regexIndex++;
		}
		if (regexIndex < re.length()) {
			printf("Regex index not at the end\n");
			// now make sure all of the remaining regex is starred
			while (regexIndex < re.length()) {
				if (!isStarred(re, regexIndex)) {
					printf("Regex %c isn't starred so false\n", re[regexIndex]);
					return false;
				}
				regexIndex += 2;  // account for the star
			}
		}
		return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().isMatch("aa", "a") << endl;
	cout << Solution().isMatch("aa", "aa") << endl;
	cout << Solution().isMatch("aa", "a*") << endl;
	cout << Solution().isMatch("aa", "a*aaa*") << endl;
	cout << Solution().isMatch("aab", "a*aaa*b") << endl;
	//cout << Solution().isMatch("ab", ".*") << endl;
	//cout << Solution().isMatch("aa", ".*a") << endl;

    return 0;
}
