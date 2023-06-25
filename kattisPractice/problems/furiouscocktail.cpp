#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    cin >> n >> t;

	vector<int> potions;
	for (int i=0; i<n; i++) {
		ll pot;
		cin >> pot;
		potions.push_back(pot);
	}
	sort(potions.rbegin(), potions.rend());
	cout << "P" << endl;

	for (int i=0; i<n; i++) {
		if (potions[i] < (n-i)*t-t) {
			cout << "Not valid: ";	
		}
		cout << potions[i] << endl;
	}



    return 0;
}
