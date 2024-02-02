#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		map<int, int> appearances;
		int target = floor(nums.size() / 3) + 1;  // + 1 because we want it to be strictly greater
		vector<int> out; 

		for (int &n : nums) {
			if (appearances.count(n)) {
				int current = appearances[n];
				if (current >= target) {  // if we have already seen this value enough times, ignore it for future times
					continue;
				}

				if (current + 1 == target) {
					out.push_back(n);
				}
				appearances[n]++;
			} else {  // we haven't seen it yet
				if (target == 1) {
					out.push_back(n);
				}
				appearances[n] = 1;
			}
		}
		return out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums = {3, 2, 3};
	vector<int> out = Solution().majorityElement(nums);
	for (int n : out) {
		cout << n << " ";
	}
	cout << endl;

	vector<int> num1 = {1};
	vector<int> out1 = Solution().majorityElement(num1);
	for (int n : out1) {
		cout << n << " ";
	}
	cout << endl;
    return 0;
}
