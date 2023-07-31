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
    ll t;
    cin >> t;
	priority_queue<int> pq;
	while (t--) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int cost = 0;
	int i = 1;
	while (!pq.empty()) {
		int price = pq.top();
		pq.pop();
		if (i % 3) {
			cost += price;
		}
		i++;
	}
	cout << cost << endl;

    return 0;
}
