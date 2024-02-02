#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
	int rangeSum(int end) {
		return (0.5*end*(end+1));
	}

	int rangeSum(int start, int end) {
		return (0.5*end*(end+1)) - (0.5*start*(start+1));
	}

    int totalMoney(int n) {
        // First 7 days is sum(0, 7)
		// Next 7 is sum(1, 8)
		int fullWeeks = n/7;
		int fullWeekSum = rangeSum(7) * fullWeeks + (rangeSum(fullWeeks-1) * 7);
		int remainingWeek = rangeSum(fullWeeks, fullWeeks+n%7);
		return fullWeekSum + remainingWeek;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().totalMoney(4) << endl;
	cout << Solution().totalMoney(10) << endl;
	cout << Solution().totalMoney(20) << endl;

    return 0;
}
