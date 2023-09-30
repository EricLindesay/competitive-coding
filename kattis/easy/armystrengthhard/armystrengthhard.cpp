#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int G, M;
		cin >> G >> M;
		priority_queue<int, vector<int>, less<int>> gArmy;
		priority_queue<int, vector<int>, less<int>> mArmy;

		for (int i=0; i<G; i++) {
			int val;
			cin >> val;
			gArmy.push(val);
		}
		for (int i=0; i<M; i++) {
			int val;
			cin >> val;
			mArmy.push(val);
		}

		while (!gArmy.empty() && !mArmy.empty()) {
			if (gArmy.top() == mArmy.top()) {
				mArmy.pop();
			} else if (gArmy.top() < mArmy.top()) {
				gArmy.pop();
			} else {
				mArmy.pop();
			}
		}

		if (gArmy.empty() && mArmy.empty()) {
			cout << "uncertain" << endl;
			continue;
		}
		if (gArmy.empty()) {
			cout << "MechaGodzilla" << endl;
			continue;
		}
		if (mArmy.empty()) {
			cout << "Godzilla" << endl;
			continue;
		}
	}

    return 0;
}
