#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
		if (s.size() > t.size()) {
			return false;
		}
		string::iterator p1 = s.begin();
		string::iterator p2 = t.begin();
		while (p2 != t.end() && p1 != s.end()) {
			if (*p1 == *p2) {
				p1++;
			}
			p2++;
		}

		return (p1 == s.end());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().isSubsequence("abc", "ahbgdc") << endl;
	cout << Solution().isSubsequence("axc", "ahbgdc") << endl;

    return 0;
}
