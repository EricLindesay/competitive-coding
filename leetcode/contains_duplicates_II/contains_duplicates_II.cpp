#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int, vector<int>> m; // the value, indices the value appears at 
	int n = nums.size();
	for (int i=0; i<n; i++) {
		if (m.count(nums[i])) {  // if this character has been previously seen
			vector<int> mv = m[nums[i]];
			for (int index : mv) {
				if (i - index <= k) return true;
			}
			m[nums[i]].push_back(i);
		} else {
			m.insert(make_pair(nums[i], vector<int>{i}));
		}
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> nums = {1,0,1,1};
	int k = 1;

	cout << containsNearbyDuplicate(nums, k) << endl;
    return 0;
}
