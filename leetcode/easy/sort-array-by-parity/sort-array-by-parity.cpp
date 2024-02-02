#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;

		while (l < r) {
			while (l < nums.size() && nums[l]%2 == 0) {
				++l;
			}
			while (r >= 0 && nums[r]%2 == 1) {
				--r;
			}

			if (l >= r) {
				break;
			}

			// now l is on an odd number, r is on an even number.
			// Swap them
			int t = nums[l];
			nums[l] = nums[r];
			nums[r] = t;
		}
		return nums;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums = {3, 1, 2, 4};
	vector<int> out = Solution().sortArrayByParity(nums);
	for (int &a : out) {
		cout << a << " ";
	}
	cout << endl;
	vector<int> num1 = {0};
	vector<int> out1 = Solution().sortArrayByParity(num1);
	for (int &a : out1) {
		cout << a << " ";
	}
	cout << endl;

    return 0;
}
