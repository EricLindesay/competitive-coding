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
	int oneBits(int n) {
		return bitset<32>(n).count();
	}

    vector<int> countBits(int n) {
		checkpoint("start");
		vector<int> out(n+1, 0);
		for (int i=1; i<=n; i++) {
			out[i] = oneBits(i);
		}
		stop("start");
		print();
		return out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> a = Solution().countBits(2);
	for (int b : a) {
		cout << b << ", ";
	}
	cout << endl;

	vector<int> b = Solution().countBits(5);
	for (int c : b) {
		cout << c << ", ";
	}
	cout << endl;

	vector<int> c = Solution().countBits(100000);
	//for (int d : c) {
	//	cout << d << ", ";
	//}
	//cout << endl;

    return 0;
}
