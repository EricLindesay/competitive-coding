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

	void eat(string s, int& s_i, char starChar, int& numEaten) {
		// loop through `s` and find how many starChars there are in a row
		while (s[s_i] == starChar) {
			numEaten++;
			s_i++;
		}
	}

	bool matches(char c1, char c2) {
		return (c1 == c2 || c1 == '.' || c2 == '.');
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
		int s_i = 0;
		int re_i = 0;
		while (re_i < re.length()) {
			// look at the first regex. Is it starred?
			if (isStarred(re, re_i)) {
				// if its starred then eat
				starChar = re[re_i];
				eat(s, s_i, starChar, numEaten);
				re_i += 2;  // Increase by 2 to skip over the character and the star
			} else {
				// Does it match the current star character?
				if (re[re_i] == starChar) {
					numEaten--;
					if (numEaten < 0) { // you have eaten to many so die
						printf("Eaten too many\n");
						return false;
					}
					re_i++;
				} else {
					// remove the starred character, make sure s matches this char
					starChar = '\0';
					if (s[s_i] != re[re_i]) {
						printf("They didn't match\n");
						return false;
					}
					s_i++;
					re_i++;
				}
			}
		}
		
		if (s_i != s.length()) {
			printf("We haven't seen all characters in s yet\n");
			return false;
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
	cout << Solution().isMatch("aab", "a*aaa*b*") << endl;
	//cout << Solution().isMatch("ab", ".*") << endl;
	//cout << Solution().isMatch("aa", ".*a") << endl;

    return 0;
}
