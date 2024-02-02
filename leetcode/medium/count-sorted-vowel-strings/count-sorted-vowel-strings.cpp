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
	vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

	int countVowelStrings(int n, char prev=0) {
		if (n == 0) {
			return 1;
		}
		int ans = 0;
		for (char vowel : vowels) {
			if (vowel >= prev) {
				ans += countVowelStrings(n-1, vowel);
			}
		}
		return ans;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().countVowelStrings(1) << endl;
	cout << Solution().countVowelStrings(2) << endl;
	cout << Solution().countVowelStrings(33) << endl;

    return 0;
}
