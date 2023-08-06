#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, X;
    cin >> n >> X;

	vector<int> prices(n);
	for (int &price : prices) {
		cin >> price;
	}

	sort(prices.begin(), prices.end());

	int marks = 1;
	for (int i=0; i<n; i++) {
		// look at the two "biggest" numbers, can you pair these to be less than X?
		for (int j=i+1; j<n; j++) {
			if (prices[i] + prices[j] <= X) {
				marks++;
				break;
			} else {
				break;
			}
		}
	}

	cout << marks << endl;

    return 0;
}
