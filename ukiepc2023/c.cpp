#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	double n, k;
	vector<double> angles(n);
	for (double &i : angles) {
		cin >> i;
	}

	double a = 360/k;

	vector<double> optimal(k);
	optimal[0] = 0;
	optimal[1] = a;
	for (int i=2; i<k; i++) {
		optimal[i] = a * optimal[i-1];
	}

	vector<int> new_optimal(k);
	vector<int> used_points(n);
	for (int i=0; i<k; i++) {
		int dist = INT_MAX;
		// Find the closest point to optimal[i]
		for (int j=0; i<n; j++) {
			int dist1 = abs(optimal[i] - angles[j]);
			int dist2 = abs(optimal[i] - 360) + angles[j];
			if (dist > min(dist1, dist2)) {
				// overwrite dist
				dist = min(dist1, dist2);
				new_optimal[i] = angles[j];
			}
		}
	}

	

    return 0;
}
