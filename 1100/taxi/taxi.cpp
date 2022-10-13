#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
	vector<short> groups(n, 0);

	for (int i=0; i<n; i++) {
		short number;
		cin >> number;
		groups[i] = number;
	}

	sort(groups.rbegin(), groups.rend());

	// loop forward through all the 'large' numbers. Then while it doesn't reach the max, loop
	// backwards through the 'small' numbers until you fill the taxi
	
	ll fp = 0;
	ll bp = groups.size() - 1;
	int taxi_size = 4;
	ll count = 0;

	while (fp <= bp) {
		count++;
		int current_taxi = groups[fp];
		while (current_taxi < taxi_size) {
			// look at back pointer.
			// See if incrementing it will exceed taxi size
			// if it does, break.
			// otherwise 'increment' bp
			if (current_taxi + groups[bp] > taxi_size) {
				break;
			} else {
				// add the group to the taxi
				current_taxi += groups[bp];
				bp--;
			}
		}
		fp++;
	}

	cout << count;

    return 0;
}
