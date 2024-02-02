#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
		int pairs = 0;
		map<int, int> seen;
		for (int &num : nums) {
			if (seen.count(num)) {  // its already been seen. We know that this position is greater than the other position. This is a good pair.
				pairs += seen[num];
				seen[num]++;
			} else {
				seen[num] = 1;
			}
		}
		return pairs;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums0 = {1, 2, 3, 1, 1, 3};
	cout << Solution().numIdenticalPairs(nums0) << endl;
	vector<int> nums1 = {1, 1, 1, 1};
	cout << Solution().numIdenticalPairs(nums1) << endl;
	vector<int> nums2 = {1, 2, 3};
	cout << Solution().numIdenticalPairs(nums2) << endl;

    return 0;
}
