#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef std::pair<int, int> pii;
typedef vector<int> vi;

vector<int> alice;
vector<int> bob;

int cmp(const vi &a, const vi &b) {
	if (a[0] < b[0]) {
		return a[0];
	} else if (a[0] > b[0]) {
		return b[0];
	} else {  // they are equal
		return a[2] > b[2];
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;
		alice = vector<int>(n);
		bob = vector<int>(n);
		for (int &a : alice) {
			cin >> a;
		}
		for (int &b : bob) {
			cin >> b;
		}

		vector<bool> removed(n, false);

		priority_queue<vector<int>, vector<int>> aliceP;
		priority_queue<vector<int>, vector<int>> bobP;
		for (int i=0; i<n; i++) {
			vector<int> a {bob[i]-1, i, alice[i]};
			aliceP.push(a);
			bobP.push({alice[i]-1, i, bob[i]});
			cout << bob[i]-1 << " " << alice[i]-1 << endl;
			//aliceProfit[i] = bob[i] - 1;
			//bobProfit[i] = alice[i] - 1;
		}

		int score = 0;
		int turn = 0;
		while (turn < n) {
			if (turn%2 == 0) {
				while (removed[aliceP.top().second])
					aliceP.pop();
				// This one hasn't been removed yet
				score += aliceP.top().first;
				removed[aliceP.top().second] = true;
				aliceP.pop();
			} else {
				while (removed[bobP.top().second])
					bobP.pop();
				// This one hasn't been removed yet
				score -= bobP.top().first;
				removed[bobP.top().second] = true;
				bobP.pop();
			}
			turn++;
		}
		cout << score << endl;
	}

    return 0;
}
