#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	list<int> nums;
	list<int> seen_potions;
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
				list<int>::iterator insert_pos = seen_potions.begin();
				for (list<int>::iterator it=seen_potions.begin(); it != seen_potions.end(); ++it) {
					if (*it < num) {
						insert_pos = it;
						break;
					}
				}
				seen_potions.insert(insert_pos, num);
				size_seen++;

			} else {  // it will kill you
				if (size_seen <= 0) {
					continue;
				}
				int worst_potion = seen_potions.back();
				if (num > worst_potion) {  // if the current num is better than the other
					// replace the previous worst potion.
					seen_potions.pop_back();
					// the number drunk does not change

					// put the current potion into seen potions
					list<int>::iterator insert_pos = seen_potions.begin();
					for (list<int>::iterator it=seen_potions.begin(); it != seen_potions.end(); ++it) {
						if (*it < num) {
							insert_pos = it;
							break;
						}
					}
					seen_potions.insert(insert_pos, num);
					health += num-worst_potion;  // heal by the difference between the two potions
				}
			}
		}
	}
	cout << drunk << endl;

    return 0;
}
