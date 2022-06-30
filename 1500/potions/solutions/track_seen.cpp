#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> insert_into_seen(vector<int> seen_potions, int size_seen, int potion) {
	if (size_seen <= 0) {
		seen_potions.push_back(potion);
		return seen_potions;
	}

	vector<int> return_list;
	bool inserted = false;
	for (int num: seen_potions) {
		if (num < potion) {  // insert the new one before the old
			inserted = true;	
			return_list.push_back(potion);
			return_list.push_back(num);
		} else {
			return_list.push_back(num);
		}
	}
	if (!inserted) {
		return_list.push_back(potion);
	}
	return return_list;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	vector<int> nums;
	vector<int> seen_potions;
	int size_seen = 0;
	int health = 0;
	int drunk = 0;
	for (int i=0; i<n; i++) {
		int num;
		cin >> num;

		if (num >= 0) {
			drunk++;
			health += num;
		} else {  // its a bad potion
			if (health+num >= 0) { // it won't kill you 
				drunk++;
				health += num;
				// put it into seen potions (sorted)
				seen_potions = insert_into_seen(seen_potions, size_seen, num);
				size_seen++;
			} else {  // it will kill you
				if (size_seen <= 0) {
					continue;
				}
				int worst_potion = seen_potions[size_seen-1];
				if (num > worst_potion) {  // if the current num is better than the other
					// replace the previous worst potion.
					seen_potions.pop_back();
					// the number drunk does not change

					// put the current potion into seen potions
					seen_potions = insert_into_seen(seen_potions, size_seen, num);
					health += num-worst_potion;  // heal by the difference between the two potions
				}
			}
		}
	}
	cout << drunk << endl;

    return 0;
}
