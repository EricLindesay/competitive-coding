#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p || p == ".*")
			return 1;

    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().isMatch("aa", "a") << endl;
	cout << Solution().isMatch("ab", ".*") << endl;
	cout << Solution().isMatch("aa", "a*") << endl;
	cout << Solution().isMatch("aa", "a*a") << endl;
	cout << Solution().isMatch("aa", ".*a") << endl;

    return 0;
}
