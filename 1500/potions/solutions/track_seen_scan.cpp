#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	vector<long long> nums;
	vector<long long> seen_potions;
	int size_seen = 0;
	long long health = 0;
	int drunk = 0;
	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;

		if (num >= 0) {
			drunk++;
			health += num;
		} else {  // its a bad potion
			if (health+num >= 0) { // it won't kill you 
				// so just add it on
				drunk++;
				health += num;
				seen_potions.push_back(num);
				size_seen++;
			} else {  // it will kill you
				if (size_seen <= 0) {
					continue;
				}
				// can we find a potion that we have already seen and replace it with this one?
				long long worst_potion = seen_potions[0];
				int worst_pos = 0;
				for (int i=1; i<size_seen; i++) {
					if (seen_potions[i] < worst_potion) {
						worst_potion = seen_potions[i];
						worst_pos = i;
					}
				}
				if (num > worst_potion) {
					// replace the previous worst potion.
					seen_potions[worst_pos] = num;
					health += num - worst_potion;  // heal by the difference between the two potions
				}
			}
		}
	}
	cout << drunk;

    return 0;
}
