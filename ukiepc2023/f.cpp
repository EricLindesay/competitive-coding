#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	
	vector<int> songs(2*n);
	for (int i=0; i<n; i++) {
		cin >> songs[i];
	}

	// duplicate it onto itself for sliding window
	for (int i=0; i<n; i++) {
		songs[i+n] = songs[i];
	}

	// SLiding window size is n
	int l = 0;

	vector<int> out(n, 0);
	// Process the first time round naively
	// store the time nad number of ads
	int ads = 0;
	int remaining_time = 0;
	for (int i=0; i<n-1; i++) {
		remaining_time += songs[i];
		if (remaining_time >= c) {
			remaining_time = 0;
			ads++;
		}
	}
	out[0] = ads;

	// Now process hte other ones using sliding window
	while (l < n) {
		// Remove the first one
		// Add a new one to the end
		int diff = songs[l+n - 1] - songs[l];
		remaining_time += diff;
		if (remaining_time < 0) {
			ads--;
			remaining_time = 0;
		}
		if (remaining_time >= c) {
			ads++;
			remaining_time = 0;
		}
		l++;
		out[l] = ads;
	}

	for (int &o : out) {
		cout << o << " ";
	}

    return 0;
}
