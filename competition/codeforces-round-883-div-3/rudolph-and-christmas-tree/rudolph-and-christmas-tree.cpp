#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n, d, h;
		cin >> n >> d >> h;

		int previous_branch = INT32_MIN;  // just so we know it won't be an issue

		double area = 0;
		while (n--) {
			double branch;
			cin >> branch;
			
			// if this branch cuts off the previous branch, work out by how much, then subtract that
			double cutoffHeight = previous_branch + h - branch;
			if (cutoffHeight > 0) {
				double base = (cutoffHeight / h) * d;

				area -= 1.0/2.0 * base * cutoffHeight;
			}
			
			// add the area of this triangle
			// area of triangle = half * base * height
			area += 1.0/2.0 * d * h;

			previous_branch = branch;
		}
		printf("%lf\n", area);
	}

    return 0;
}
