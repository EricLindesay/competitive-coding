#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		sort(nums.begin(), nums.end());

		int longest = 1;
		int current = 1;
		for (int i=1; i<nums.size(); ++i) {
			if (abs(nums[i] - nums[i-1]) == 1) {  // if they are adjacent
				++current;
			} else if (abs(nums[i] - nums[i-1]) == 0) { // they are the same number so don't do anything
				continue;
			} else {
				cout << "Not adjacent " << nums[i] << " " << nums[i-1] << endl;
				current = 1;
			}

			longest = max(longest, current);
		}
		return longest;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> in = {1, 2, 0, 1};
	printf("%d\n", Solution().longestConsecutive(in));

    return 0;
}
