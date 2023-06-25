#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
	vector<int> ans(2, -1);
	int n = nums.size();

	vector<int> freq(n+1, 0);
	for (int i=0; i<n; i++) {
		if (++freq[nums[i]] == 2) ans[0] = nums[i];
	}

	for (int i=1; i<n+1; i++) {
		if (freq[i] == 0) {
			ans[1] = i;
			break;
		}
	}
	return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> nums = {1, 2, 3, 4, 5, 5};
	for (int i : findErrorNums(nums)) {
		cout << i << " ";
	}
	cout << endl;

	nums = {1, 2,2,4};
	for (int i : findErrorNums(nums)) {
		cout << i << " ";
	}
	cout << endl;

	nums = {2,2};
	for (int i : findErrorNums(nums)) {
		cout << i << " ";
	}
	cout << endl;

	nums = {1,2,4,2};
	for (int i : findErrorNums(nums)) {
		cout << i << " ";
	}
	cout << endl;
    return 0;
}
