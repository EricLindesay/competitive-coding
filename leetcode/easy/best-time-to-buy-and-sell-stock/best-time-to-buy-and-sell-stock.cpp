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
    int maxProfit(vector<int>& prices) {
		int lowest = INT_MAX;
		int profit = 0;
		for (int i=0; i<prices.size(); i++) {
			lowest = min(lowest, prices[i]);
			
			profit = max(profit, prices[i] - lowest);
		}
		return profit;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> a = {7, 1, 5, 3, 6, 4};
	cout << Solution().maxProfit(a) << endl;
	vector<int> b = {7, 6, 4, 3, 1};
	cout << Solution().maxProfit(b) << endl;

    return 0;
}
