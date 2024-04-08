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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());

		set<int> result;
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
		return vector<int>(result.begin(), result.end());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> a{1, 2, 2, 1};
	vector<int> b{2, 2};
	vector<int> c = Solution().intersection(a, b);

	for (int i : c) {
		cout << i << " ";
	}
	cout << endl;

    return 0;
}
