#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class Solution {
public:
	string reverse(string s) {
		string t;
		for (int i=0; i < s.length(); i++) {
			t += s[s.length() - 1 - i];
		}
		return t;
	}

    string longestPalindrome(string s) {
		string reversed = reverse(s);
		for (int i=s.length() - 1; i >= 0; i--) {
			for (int start=0; start <= s.length() - i - 1; start++) {
				if (s.substr(start, i+1) == reversed.substr(s.length() - start -  (i+1), i+1))
					return s.substr(start, i+1);
			}
		}
		return "";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cout << Solution().longestPalindrome("babad") << " bab" << endl;
	cout << Solution().longestPalindrome("cbbd") << " bb" << endl;

    return 0;
}
