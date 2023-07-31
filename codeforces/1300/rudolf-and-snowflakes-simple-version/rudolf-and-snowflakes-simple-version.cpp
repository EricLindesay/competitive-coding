#include <iostream>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;

		bool success = false;
		for (int k=0; k<n; k++) {
			// see if there exists a snow flake with this k value
			int min = 1 + k + pow(k,2);
			if (n < min)
				break;

			// find log_k
			int s = ceil(log(n)/log(k));  // = log_k(n)
			double sum = (1 - pow(k, s)) / (1 - k);
			if (sum == n) {
				success = true;
				break;
			}
		}

		if (success)
			printf("YES\n");
		else
			printf("NO\n");
	}

    return 0;
}
