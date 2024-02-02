#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, c;
    cin >> n >> c;

	vector<int> songs(n);
	for (int &s : songs) {
		cin >> s;
	}

	vector<int> out(n, 0);
	for (int start = 0; start < n; start++) {
		int running_sum = 0;
		// look at the start to the end
		for (int i=start; i<n - 1; i++) {
			running_sum += songs[i];
			if (running_sum >= c) {
				running_sum = 0;
				out[start]++;
			}
		}
		if (start != 0) {
			running_sum += songs[n-1];
			if (running_sum >= c) {
				running_sum = 0;
				out[start]++;
			}
		}
		// look at 0 to start
		for (int i=0; i<start-1; i++) {
			running_sum += songs[i];
			if (running_sum >= c) {
				running_sum = 0;
				out[start]++;
				
			}
		}
	}

	for (int i=0; i<n; i++) {
		cout << out[i] << " ";
	}

    return 0;
}
