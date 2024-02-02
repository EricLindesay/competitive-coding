#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	double q;
	cin >> n >> q;

	vector<double> prices(n);
	double money = 100;
	double stocks = 0;
	double buyPrice = 0;

	for (int i=0; i<n; i++) {
		double price;
		cin >> price;
		prices[i] = price;
	}

	// Go through the prices and find every consecutive increasing section.
	// then just delete the ones between it

	double prev = prices[0];
	double ind = 0;
	vector<pair<double, double>> priceProfit;
	for (int i=1; i<n; i++) {
		// find sections of increasing price
		if (prices[i] > prices[i-1]) {
			if (i-1 != ind) {
				priceProfit.push_back(make_pair(prev, prices[i-1]-prev));
			}
		}
	}


    return 0;
}
