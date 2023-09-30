#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void printVector(vector<int> &v) {
	for (int &e : v) {
		cout << e << " ";
	}
	cout << endl;
}

class Solution {
public:
    int getMaximumGenerated(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
        vector<int> nums(n+1);
		nums[0] = 0;
		nums[1] = 1;
		int maxVal = 1;
		for (int i=0; i<nums.size(); i++) {
			if (2 * i >= 2 && 2 * i <= n) {
				nums[2*i] = nums[i];
			}
			if (2 * i + 1 >= 2 && 2 * i + 1 <= n) {
				nums[2 * i + 1] = nums[i] + nums[i+1];
				maxVal = max(nums[2 * i + 1], maxVal);
			}
		}
		return maxVal;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().getMaximumGenerated(7) << endl;
	cout << Solution().getMaximumGenerated(2) << endl;
	cout << Solution().getMaximumGenerated(3) << endl;
	cout << Solution().getMaximumGenerated(0) << endl;
	cout << Solution().getMaximumGenerated(1) << endl;

    return 0;
}
