#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> nums;
	for (int i=0; i<200000; i++) {
		nums.push_back(200000-i);
	}
	sort(nums.begin(), nums.end());

	int ans = 0;
	for (int i=0; i<200000; i++) {
		ans += nums[i];
	}
}
