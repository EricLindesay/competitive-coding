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
		int n = nums.size();
		int output = 0;
		int modulo = pow(10, 9) + 7;
		vector<int> revs(n);
		for (int i=0; i<n; i++) {
			nums[i] -= rev(nums[i]);
		}
		// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
		// ===
		// nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
		// (nums[i] - rev(nums[i])) - (nums[j] - rev(nums[j])) == 0
		// Then it just becomes a two-sum problem

		map<int, int> seen;
		for (int i=0; i<n; i++) {
			// See if this number is already in the map
			// If it is, increment output by the map amount
			// increment the map amount
			if (seen.count(nums[i])) {
				output += seen[nums[i]];
				output %= modulo;
				seen[nums[i]]++;
			} else {
				seen[nums[i]] = 1;
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
	vector<int> num2 {13, 10, 35, 24, 76};
	cout << Solution().countNicePairs(num2) << endl;

    return 0;
}
