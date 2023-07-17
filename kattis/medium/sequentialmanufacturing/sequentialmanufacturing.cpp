#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;

	vector<ll> t(n);
	vector<int> k(n);

	ll totalSum = 0;
	ll maxT = 0;
	// read the products
	for (int i=0; i<n; i++) {
		cin >> t[i];
		totalSum += t[i];
		maxT = max(maxT, t[i]);
	}

	// read in the input areas. This isn't needed but its nice for easier debugging
	k[0] = 0;  // the first machine has an input area of 0
	for (int i=1; i<n; i++) {
		cin >> k[i];
	}

	ll time = maxT * (p-1) + totalSum; // time assuming you don't have to wait
	cout << time << endl;

    return 0;
}
