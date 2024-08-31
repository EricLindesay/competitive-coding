#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int allXOR(vector<int> ns) {
	return ns[0]%2*1 ^ ns[1]%2*2 ^ ns[2]%2*3 ^ ns[3]%2*4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		vector<int> ns(4, 0);
		for (int i=0; i<4; i++) {
			cin >> ns[i];
		}
		int wins = ns[3]/2;
		ns[3] = 0;
		
		if (!(ns[0]%2 == ns[1]%2 && ns[1]%2 == ns[2]%2)) {
			int parity = ns[0]%2+ns[1]%2+ns[3]%2;

			if (parity%2) {
				// Remove the even one
				for (int i=0; i<3; i++) {
					if (ns[i] > 0 && ns[i]%2 == 0) {
						ns[i]--;
					}
				}
			} else {
				if (ns[0] == 0 && parity == 0) {
					ns[1]--;
					ns[2]--;
				} else {

				}
				// Remove the odd one
				for (int i=0; i<3; i++) {
					if (ns[i] > 0 && ns[i]%2) {
						ns[i]--;
					}
				}
			}
		}
		cout << ns[0] << " " << ns[1] << " " << ns[2] << " " << ns[3] << endl;
		wins += (ns[2]+1)/2;
	//	int highest = (int) *max_element(ns.begin(), ns.end()-1);
	//	wins += (highest+1)/2;
		wins += ns[0]/2 + ns[1]/2;

		cout << wins << endl;
	}

    return 0;
}
