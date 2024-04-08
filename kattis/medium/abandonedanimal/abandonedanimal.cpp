#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

map<ll, int> cache;

int rec(map<string, vector<int>> &itemPlaces, vector<string> &items, int itemIndex, int shopNum) {
	int cacheIndex = itemIndex*100000 + shopNum;
	if (cache.count(cacheIndex)) {
		return cache[cacheIndex];
	}
	// See which shops the current item can be found in
	// If there are none which are valid, return 0
	// otherwise, try each of the valid shops and see which of those are valid
	// If multiple are valid, return 2
	if (itemIndex == items.size())
		return 1;

	string currentItem = items[itemIndex];
	int output = 0;
	for (int i : itemPlaces[currentItem]) {
		if (i < shopNum) continue;
		else {
			output += rec(itemPlaces, items, itemIndex+1, i);
		}
	}

	cache[cacheIndex] = output;
	return output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, shop;
	string item;
    cin >> n >> k;

	start();
	map<string, vector<int>> itemPlaces;
	while (k--) {
		cin >> shop >> item;
		itemPlaces[item].push_back(shop);
	}

	cin >> k;
	vector<string> items(k);
	for (string &i : items) {
		cin >> i;
	}
	int i = rec(itemPlaces, items, 0, 0);
	if (i == 0) {
		cout << "impossible";
	} else if (i == 1) {
		cout << "unique";
	} else {
		cout << "ambiguous";
	}

	stop();
	print();

    return 0;
}
