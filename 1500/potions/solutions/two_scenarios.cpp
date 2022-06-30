#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int potions_drunk(int n, vector<int> nums, int index=0, int health=0) {
	int pots = 0;
	int i = index;
	while (i < n) {
		if (nums[i] < 0) {
			// consider whether to drink it
			if (health+nums[i] >= 0) { // we have enough health to drink it if we want to
				break;	
			}
		} else {
			health += nums[i];
			pots++;
		}

		i++;
	}
	if (i < n) {
		// now we have a negative potion that we can drink at nums[0]
		int newi = i+1;
		int p1 = potions_drunk(n, nums, newi, health+nums[i]) + 1; // drink the bad potion
		int p2 = potions_drunk(n, nums, i, health); // don't drink it
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
