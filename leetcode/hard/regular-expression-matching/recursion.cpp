#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

using namespace std;

class Solution {
public:
	map<int, bool> memory;

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
		string ret = re.substr(0, 3);
		for (int i=3; i<re.length(); i++) {
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

	bool recursion(string s, int s_i, string re, int re_i, int depth) {
		if (memory.find(s_i*30 + re_i) != memory.end())
			return memory[s_i*30 + re_i];
			
//		int t = re_i+1;
//		if (isStarred(re, re_i)) t++;
//		printf("%d Recursion: %s %s\n", depth, s.substr(0, s_i+1).c_str(), re.substr(0, t).c_str());

		if (re_i == re.length() && s_i == s.length()) {
			memory[s_i*30 + re_i] = true;
			return true;
		}
		if (re_i >= re.length()) {
			memory[s_i*30 + re_i] = false;
			return false;
		}
		if (s_i >= s.length()) {
			// make sure the rest of the regex is starred
			while (re_i < re.length()) {
				if (!isStarred(re, re_i)) {
					memory[s_i*30 + re_i] = false;
					return false;
				}
				if (re_i < re.length() - 1)
					re_i += 2;
				else {
					memory[s_i*30 + re_i] = false;
					return false;  // the next character can't be starred
				}
			}
			memory[s_i*30 + re_i] = true;
			return true;
		}

		// if it is starred
		if (isStarred(re, re_i)) {
			//printf("Is starred %s %s\n", s.substr(0, s_i+1).c_str(), re.substr(0, re_i+2).c_str());
			// do recursion based on accept or reject
			// Make sure that the character matches
			if (re[re_i] == s[s_i] || re[re_i] == '.') {
//				printf("accept the star %d\n", depth);
				if (recursion(s, s_i+1, re, re_i, depth+1)) {
					memory[s_i*30 + re_i] = true;
					return true;
				}

//				printf("Ignore the star %d\n", depth);
				if (recursion(s, s_i, re, re_i+2, depth+1)) {
					memory[s_i*30 + re_i] = true;
					return true;
				}

//				printf("accept the star exactly once %d\n", depth);
				if (recursion(s, s_i+1, re, re_i+2, depth+1)) {
					memory[s_i*30 + re_i] = true;
					return true;
				}
//				printf("you can't recursion it %d\n", depth);

				memory[s_i*30 + re_i] = false;
				return false;
			} else {
				// can you ignore the star?
				bool ret = recursion(s, s_i, re, re_i+2, depth+1);
				memory[s_i*30 + re_i] = ret;
				return ret;
			}
		} else {
			// Check that they match. If it doesn't match then you return false, otherwise continue
			if (re[re_i] == s[s_i] || re[re_i] == '.') {
				bool ret = recursion(s, s_i+1, re, re_i+1, depth+1);
				memory[s_i*30 + re_i] = ret;
				return ret;
			} else {
				// regex doesn't match :(
//				printf("Regex doesn't match\n");
				memory[s_i*30 + re_i] = false;
				return false;
			}
		}
	}

    bool isMatch(string s, string re) {
		re = simplifyRegex(re);
		return recursion(s, 0, re, 0, 0);
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
	cout << Solution().isMatch("ab", ".*") << endl;
	cout << Solution().isMatch("aa", ".*a") << endl;

    return 0;
}
