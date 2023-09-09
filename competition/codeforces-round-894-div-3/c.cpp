#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	// split the fence on the middle (if odd, ignore the exact middle element)
	// Make sure the difference between i and i+1 is the same when going throuhg the lists from opposite sides
	
	while (t--) {
		int n;
		cin >> n;
		
		vector<int> planks(n);
		for (int &plank : planks)
			cin >> plank;
		
		// edge cases
		if (n == 1) {
			if (planks[0] == 1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
			continue;
		}
		if (n == 2) {
			if (planks[0] == 2 && planks[1] == 1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
			continue;
		}
		
		// instead of checking difference between n and n-1
		// you need to check the difference between n.size() - n and n.size() - n - 2

		bool symmetrical = true;
		int l=0, r=0;
		int h=0;
		int d = 0;
		for (int z=0; z<=n/2; z++) {
			// check that the difference between the previous left and l and the previous right and r are the same
			ll horizontalDist = n-1-z;
			// Go throught the array until you find one jutting out
			for (int i=n-1-z; i>1; i--) {
				if (planks[i-1] > planks[(n-1-z)]) {
					horizontalDist = (n-1-z) - i + 1;
					break;
				}
			}
			++l;

			// get the vertical distance with the NEXT plank. Then subtract how many loops we've done
			// If the distance is zero, r++
			// if the distance is negative, r++
			ll verticalDist = planks[r] - planks[r+1] - d; 
			// loop through each plank, until vertical dist > 0
			if (verticalDist == 0) {
				while (true) {
					++r;
					if (planks[r+1] < planks[r])
						break;
				}
				d = 0;
				verticalDist = planks[r] - planks[r+1] - d; 
			}
			d++;

			if (l >= n/2 && r >= n/2) {
				symmetrical = true;
				break;
			}
			
			if (verticalDist == horizontalDist) {
				// the difference is the same, so far its symmetrical
			} else {
				symmetrical = false;
				break;
			}
		}

		if (symmetrical)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}


    return 0;
}
