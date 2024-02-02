#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i = 0, k = nums.size() - 1;
		while (k - i < 1) {  // while k is greater than i and there is atleast one element between them
			if (nums[i] >= nums[k]) {
				// this is an invalid state, change stuff

			}
		}
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums = {1,2,3,4};
	cout << Solution().find132pattern(nums) << endl;
	vector<int> nums2 = {3,1,4,2};
	cout << Solution().find132pattern(nums2) << endl;

    return 0;
}
