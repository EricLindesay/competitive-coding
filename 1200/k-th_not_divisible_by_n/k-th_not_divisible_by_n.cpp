#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long long t;
    cin >> t;
	for (int i=0; i<t; i++) {
		long long n, k;
		cin >> n >> k;

		if (k < n) {
			cout << k << endl;
			continue;
		}

		double ans = (double) (n*k)/(n-1);
		if ((int) ans%n == 0) {
			ans -= 1;
		} else {
			ans = floor(ans);
		}
		//cout << ans << endl;
		printf("%.0f\n", ans);
	}

    return 0;
}
