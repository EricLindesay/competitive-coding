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
    string maximumOddBinaryNumber(string s) {
        // Count how many ones and zeros there are.
		int numOnes = 0;
		for (auto it = s.begin(); it != s.end(); it++) {
			numOnes += (*it) == '1';
		}

		// Add all the leading ones
		string output(numOnes-1, '1');
		// Add on all the zeros
		output.append(s.size()-numOnes, '0');
		// Add on the last one
		output += '1';
		return output;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().maximumOddBinaryNumber("010") << endl;
	cout << Solution().maximumOddBinaryNumber("0101") << endl;

    return 0;
}
