#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class Solution {
public:
	bool isStarred(string re, int index) {
		if (index <= re.length() - 2) {
			if (re[index+1] == '*') {
				return true;
			}
		}
		return false;
	}

	string simplifyRegex(string re) {
		// Remove repeated stars. a*a* should simplify to a*.
		// a*.* and .*a* should simplify to .*
		string ret = "";
		for (int i=0; i<re.length(); i++) {
			if (re[i] == '*' && ret.size() > 3) {
				if (ret[ret.size() - 3] == re[i-1] && isStarred(ret, ret.size() - 3)) {
					ret = ret.substr(0, ret.length()-1); // ignore the character just before the star
				} else if (ret[ret.size() - 3] == '.' && isStarred(ret, ret.size() - 3)) {
					// if the current character is starred and you already had a '.' then ignore the current one
					ret = ret.substr(0, ret.length()-1);
				} else if (ret[ret.size() - 1] == '.' && isStarred(ret, ret.size() - 3)) {
					ret = ret.substr(0, ret.length() - 3);
					ret += ".*";
				} else {
					ret += re[i];
				}
			} else {
				ret += re[i];
			}
		}
		return ret;
	}

	bool vomit(string s, int s_i, string re, int &re_i, char starChar, int &numEaten) {
		printf("vomiting num eaten = %d\n", numEaten);
		int numVomited = 0;
		while (re_i < re.length() && (re[re_i] == starChar || starChar == '.')) {
			// if it is starred, then don't consider it, stop vomiting
			printf("re[re_i] = %c\n", re[re_i]);
			if (isStarred(re, re_i)) {
				break;
			}
			numEaten--;
			if (numEaten < 0) {
				// You got told to eat 4 but there are only 3 available.
				printf("Num eaten, return false\n");
				return false;
			}
			re_i++;	
			numVomited++;
		}
		printf("Vomited %d characters\n", numVomited);

		// loop through the ones you vomited, make sure that they match the eaten characters
		int indexCopy = re_i;
		for (int i=0; i<numVomited; i++) {
			indexCopy--;
			printf("Checking the vomit: %c != %c\n", s[s_i-(i+1)], re[indexCopy]);
			if (!matches(s[s_i-(i+1)], re[indexCopy])) {
				printf("Vomiting not equal\n");
				return false;
			}
		}

		return true;
	}

	void eat(string s, int& s_i, char starChar, int& numEaten) {
		// loop through `s` and find how many starChars there are in a row
		while (s_i < s.length() && matches(s[s_i], starChar)) {
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
				char prevStar = starChar;
				int prevNum = numEaten;
				starChar = re[re_i];
				numEaten = 0;
				printf("Commence eating for %c", starChar);
				eat(s, s_i, starChar, numEaten);
				printf(" you ate %d\n", numEaten);
				if (numEaten == 0) {
					starChar = prevStar;
					numEaten = prevNum;
				}
				re_i += 2;  // Increase by 2 to skip over the character and the star
			} else {
				// If it's not starred, its a single character.
				// If the single character matches the previous star, then vomit
				// Otherwise, check they match exactly
				// If it's not starred, then try vomiting, then remove the star
				// when vomiting, you have to check that the one you vomit matches the one in s
				// try vomiting if you can

				if (re[re_i] == starChar || starChar == '.') {
					if (!vomit(s, s_i, re, re_i, starChar, numEaten)) {
						return false;
					}
					starChar = '\0';
					numEaten = 0;
				} else {
					// we are matching a single character to a single character
					// remove the starred character, make sure s matches this char
					starChar = '\0';
					numEaten = 0;
					printf("%c matches %c?\n", s[s_i], re[re_i]);
					if (!matches(s[s_i], re[re_i])) {
						printf("They didn't match\n");
						return false;
					}
					s_i++;
					re_i++;
				}
			}
		}
		
		if (s_i != s.length()) {
			printf("We haven't seen all characters in s yet. We have only seen %s, %d, %d\n", s.substr(0, s_i+1).c_str(), s_i, s.length());
			return false;
		}

		return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
//	cout << Solution().isMatch("aa", "a") << endl;
//	cout << Solution().isMatch("aa", "aa") << endl;
//	cout << Solution().isMatch("aa", "a*") << endl;
//	cout << Solution().isMatch("aa", "a*aaa*") << endl;
//	cout << Solution().isMatch("aa", "a*aa*") << endl;
//	cout << Solution().isMatch("aab", "a*aaa*b*") << endl;
//	cout << Solution().isMatch("aab", ".*aab.*") << endl;
//	cout << Solution().isMatch("mississippi", "mis*is*ip*.") << endl;
//	cout << Solution().isMatch("ab", ".*c") << endl;
//	cout << Solution().isMatch("aaa", "ab*a*c*a") << endl;
//	cout << Solution().isMatch("bbbba", ".*a*a") << endl;
	cout << Solution().isMatch("aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*") << endl;
	//cout << Solution().isMatch("ab", ".*") << endl;
	//cout << Solution().isMatch("aa", ".*a") << endl;

    return 0;
}
