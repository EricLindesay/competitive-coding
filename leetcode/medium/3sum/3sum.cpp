#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		set<vector<int>> values;

		for (int i=0; i<nums.size(); i++) {
			int left = i+1;
			int right = nums.size() - 1;
			// move left and right inwards, looking for a pair which add to the thingy
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					values.insert({nums[i], nums[left], nums[right]});
					left++;
					right--;
				} else if (sum < 0) {
					left++;
				} else {
					right--;
				}
			}
		}
		
		// convert from set to vector
		vector<vector<int>> output(values.size());
		set<vector<int>>::iterator it = values.begin();
		for (int i=0; i<values.size(); i++) {
			vector<int> v = *it;
			output[i] = vector<int>(v.begin(), v.end());
			it++;
		}
		return output;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> vect = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
	vector<vector<int>> out = Solution().threeSum(vect);

	for (int i=0; i<out.size(); i++) {
		for (int j=0; j<out[0].size(); j++) {
			cout << out[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Expected: [[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]" << endl;

    return 0;
}
