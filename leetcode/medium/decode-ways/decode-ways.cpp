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
	set<string> valid {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};

	bool isValid(string s) {
		return valid.find(s) != valid.end();
	}

    int numDecodings(string s) {
		if (s.size() == 0) {
			return 0;
		}
		checkpoint("func");
		cout << "Checking " << s << endl;
        // naive way first
		int decodings = 0;
		if (isValid(string{s[0]})) {
			cout << s[0] << " is valid" << endl;
			decodings += numDecodings(s.substr(1)) + 1;
		} 
		if (isValid(string{s[0], s[1]})) {
			cout << s[0] << s[1] << " is valid" << endl;
			decodings += numDecodings(s.substr(2)) + 1;
		}

		return decodings;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	start();
	cout << Solution().numDecodings("11106") << endl; // 2
	stop("func");
	stop();
	print();
	cout << Solution().numDecodings("12") << endl;    // 2
	cout << Solution().numDecodings("226") << endl;   // 3
	cout << Solution().numDecodings("06") << endl;    // 0

    return 0;
}
