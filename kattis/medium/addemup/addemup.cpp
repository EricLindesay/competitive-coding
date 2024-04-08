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

map<int, int> dFlip {{
	make_pair(8, 8),
	make_pair(1, 1),
	make_pair(0, 0),
	make_pair(6, 9),
	make_pair(9, 6),
	make_pair(2, 2),
	make_pair(5, 5),
}};

int flip(int num) {
	// returns -1 if the card cannot be flipped
	// rotate a number 180 degrees. This can only be done if the number contains only flippable numbers
	// 1, 8, 0, 9, 6, 2, 5
	int flipped = 0;
	int digit = num%10;
	while (num > 0) {
		if (digit == 3 || digit == 4 || digit == 7) {
			return -1;  // can't be flipped
		}
		flipped = flipped * 10 + dFlip[digit];  // might be able to make it slightly more efficient by just having an if/else to handle the 6 9 case
		num /= 10;
		digit = num%10;
	}
	return flipped;
}

bool twoSum(vector<int> &nums, int target) {
	// this can be done while reading in the input.
	map<int, bool> seen;
	for (int i=0; i<nums.size(); i++) {
		// if the number contains a 2 or a 5, see if that is in there as well
		// if the number contains a 6 or a 9, see if that is in there as well
		// try every combination
		int f = flip(nums[i]);
		if (f != -1) {
			if (seen.count(target - f)) {
				return true;
			}
		}
		if (seen.count(target - nums[i])) {
			return true;
		}
		if (f != -1) {
			seen[f] = true;
		}
		seen[nums[i]] = true;
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
