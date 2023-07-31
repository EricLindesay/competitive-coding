#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	
	while (t--) {
		ll n, m, h;
		cin >> n >> m >> h;

		ll rudolf_points = 0;
		ll rudolf_penalty = 0;
		ll position = 1;

		for (int i=0; i<n; i++) {
			vector<ll> user(m);
			for (ll j=0; j<m; j++) {
				cin >> user[j];
			}
			// sort user
			sort(user.begin(), user.end());
			
			ll points = 0;  // how many you solve
			ll penalty = 0; // how much time you took total (for each problem)
			ll time = 0;
			for (ll problem: user) {
				time += problem;
				if (time <= h) {
					points++;
					penalty += time;
				} else {
					break;
				}
			}

			if (i > 0) {
				if (points > rudolf_points) {
					position++;
				} else if (points == rudolf_points) {
					if (penalty < rudolf_penalty) {
						position++;
					}
				}
			} else { // i == 0
				rudolf_points = points;
				rudolf_penalty = penalty;
			}
		}

		cout << position << "\n";

	}

    return 0;
}
