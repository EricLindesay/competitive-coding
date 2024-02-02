#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:

	int rev(int x) {
		int out = 0;
		while (x > 0) {
			out *= 10;
			out += x%10;
			x /= 10;
		}
		return out;
	}

    int countNicePairs(vector<int>& nums) {
		int output = 0;
		int modulo = pow(10, 9) + 7;
		vector<int> revs(nums.size());
		for (int i=0; i<nums.size(); i++) {
			revs[i] = rev(nums[i]);
		}
		// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
		// ===
		// nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
		// (nums[i] - rev(nums[i])) - (nums[j] - rev(nums[j])) == 0
		// Then it just becomes a two-sum problem
		
		for (int i=0; i<nums.size(); i++) {
			for (int j=i+1; j<revs.size(); j++) {
				if (nums[i] + revs[j] == revs[i] + nums[j]) {
					output++;
					output %= modulo;
				}
			}
		}
		return output;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums {42, 11, 1, 97};
	cout << Solution().countNicePairs(nums) << endl;

    return 0;
}
