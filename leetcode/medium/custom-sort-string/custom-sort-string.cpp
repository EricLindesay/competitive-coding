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
    string customSortString(string order, string s) {	
		vector<int> charOrder(26, 0);
		vector<int> output(s.size(), 0);

		for (int i=0; i<charOrder.size(); i++) {
			charOrder[order[i]-'a'] = i;
		}
		sort(s.begin(), s.end(), [charOrder](const char &a, const char &b){
				return charOrder[a-'a'] < charOrder[b-'a'];
				});
		return s;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().customSortString("cba", "abcd") << endl;
	cout << Solution().customSortString("bcafg", "abcd") << endl;

    return 0;
}
