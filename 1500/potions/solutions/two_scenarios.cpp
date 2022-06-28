#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int potions_drunk(int n, vector<int> nums, int health=0) {
	int pots = 0;
	while (n > 0) {
		if (nums[0] < 0) {
			// consider whether to drink it
			if (health+nums[0] >= 0) { // we have enough health to drink it if we want to
				break;	
			}
		} else {
			health += nums[0];
			pots++;
		}

		n--;
		nums.erase(nums.begin());
	}
	if (n > 0) {
		// now we have a negative potion that we can drink at nums[0]
		n--;
		int store_num0 = nums[0];
		nums.erase(nums.begin());

		int p1 = potions_drunk(n, nums, health+store_num0) + 1; // drink the bad potion
		int p2 = potions_drunk(n, nums, health); // don't drink it
		pots += max(p1, p2);
	}
	return pots;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	vector<int> nums;
	for (int i=0; i<n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	cout << potions_drunk(n, nums);

    return 0;
}
