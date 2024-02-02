#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
		if (nums.size() <= 2) {
			return true;
		}
		int direction = 0;  // right now we don't know if increasing or decreasing

		for (int i=1; i<nums.size(); i++) {
			if (nums[i] > nums[i-1]) {  // ascending
				if (direction == -1) {  // we have already seen its descending
					return false;  // so this is wrong
				} else if (direction == 0) {
					direction = 1;
				}
			} else if (nums[i] < nums[i-1]) {  // descending
				if (direction == 1) {  // we have already seen its ascending
					return false;  // so this is wrong
				} else if (direction == 0) {
					direction = -1;
				}
			}
		}
		return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums = {1, 2, 2, 3};
	cout << Solution().isMonotonic(nums) << endl;
	vector<int> num1 = {6, 5, 4, 4};
	cout << Solution().isMonotonic(num1) << endl;
	vector<int> num2 = {1, 3, 2};
	cout << Solution().isMonotonic(num2) << endl;

    return 0;
}
