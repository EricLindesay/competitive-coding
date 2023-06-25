#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	forward_list<long long> seen_potions;
	int size_seen = 0;
	long long health = 0;
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
				forward_list<long long>::iterator insert_pos = seen_potions.before_begin();
				for (forward_list<long long>::iterator it=seen_potions.begin(); it != seen_potions.end(); ++it) {
					if (*it < num) {
						insert_pos = it;
					} else {
						break;
					}
				}
				seen_potions.insert_after(insert_pos, num);
				size_seen++;

			} else {  // it will kill you
				if (size_seen <= 0) {
					continue;
				}
				int worst_potion = seen_potions.front();
				if (num > worst_potion) {  // if the current num is better than the other
					// replace the previous worst potion.
					seen_potions.pop_front();
					// the number drunk does not change

					// put the current potion into seen potions
					forward_list<long long>::iterator insert_pos = seen_potions.before_begin();
					for (forward_list<long long>::iterator it=seen_potions.begin(); it != seen_potions.end(); ++it) {
						if (*it < num) {
							insert_pos = it;
						} else {
							break;
						}
					}
					seen_potions.insert_after(insert_pos, num);
					health += num - worst_potion;  // heal by the difference between the two potions
				}
			}
		}
	}
	cout << drunk;

    return 0;
}
