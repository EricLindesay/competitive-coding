#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

vector<int> addToNums(vector<int> &nums, int a, int b) {
	vector<int> r;
	for (int i=0; i<nums.size(); i++) {
		r.push_back(nums[i] + a * pow(10, (int) log10(nums[i]) + 1));
		r.push_back(nums[i] + b * pow(10, (int) log10(nums[i]) + 1));
	}
	return r;
}

vector<int> addToNums(vector<int> &nums, int a) {
	vector<int> r;
	for (int i=0; i<nums.size(); i++) {
		r.push_back(nums[i] + a * pow(10, (int) log10(nums[i]) + 1));
	}
	return r;
}

bool addIfEmpty(vector<int> &nums, int a, int b) {
	if (nums.empty()) {
		nums.push_back(a);
		nums.push_back(b);
		return true;
	}
	return false;
}
bool addIfEmpty(vector<int> &nums, int a) {
	if (nums.empty()) {
		nums.push_back(a);
		return true;
	}
	return false;
}

vector<int> combos(int num) {
	vector<int> res;
	cout << "Split " << num << " into ";
	int digit = num%10;
	while (num > 0) {
		if (digit == 2 || digit == 5) {
			if (!addIfEmpty(res, 2, 5)) {
				res = addToNums(res, 2, 5);
			}
		} else if (digit == 6 || digit == 9) {
			if (!addIfEmpty(res, 6, 9)) {
				res = addToNums(res, 6, 9);
			}
		} else {
			if (!addIfEmpty(res, digit)) {
				res = addToNums(res, digit);
			}
		}
		num /= 10;
		digit = num%10;
	}

	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;

	return res;
}

bool twoSum(vector<int> &nums, int target) {
	// this can be done while reading in the input.
	map<int, bool> seen;
	for (int i=0; i<nums.size(); i++) {
		// if the number contains a 2 or a 5, see if that is in there as well
		// if the number contains a 6 or a 9, see if that is in there as well
		// try every combination
		vector<int> c = combos(nums[i]);
		for (int k : c) {
			cout << "Trying number " << k << endl;
			if (seen.count(target - k)) {
				cout << target - k << " and " << k << endl;
				return true;
			}
		}
		for (int k : c) {
			// add every combination to the seen map. This must be afterwards so you don't add with yourself
			seen[k] = true;
		}
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, s;
    cin >> n >> s;

	vector<int> nums(n);
	for (int &num : nums) {
		cin >> num;
	}

	cout << (twoSum(nums, s) ? "YES" : "NO");

    return 0;
}
