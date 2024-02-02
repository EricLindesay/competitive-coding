#include <bits/stdc++.h>

#define TIMER 1

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
	vector<int> cache = vector<int>(46, -1);  // 45 is the input limit
											  
    int climbStairs(int n) {
		checkpoint("func");
		if (n == 0) {
			return 1;
		}
		if (cache[n] != -1) {
			return cache[n];
		}	
        int ans = 0;
		if (n >= 1) {
			ans += climbStairs(n-1);
		}
		if (n >= 2) {
			ans += climbStairs(n-2);
		}
		cache[n] = ans;
		return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	//cout << Solution().climbStairs(2) << endl;
	//cout << Solution().climbStairs(3) << endl;
	cout << Solution().climbStairs(45) << endl;
	stop("func");
	print();

    return 0;
}
