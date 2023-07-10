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
		int n, m, h;
		cin >> n >> m >> h;

		int rudolf_points = 0;
		int rudolf_penalty = 0;
		int position = 1;

		for (int i=0; i<n; i++) {
			vector<int> user(m);
			for (int j=0; j<m; j++) {
				cin >> user[j];
			}
			// sort user
			sort(user.begin(), user.end());
			
			int points = 0;  // how many you solve
			int penalty = 0; // how much time you took total (for each problem)
			int time = 0;
			for (int problem: user) {
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
