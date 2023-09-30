#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	double n = 0;
	while (cin >> n && n != 0) {
		if (n <= 2) {
			cout << n - 1 << endl;
			continue;
		}
		n--;
		double x = -1 * 0.5 + sqrt(0.25 + 4 * 0.5 * n);
		cout << ceil(x) << endl;
	}

    return 0;
}
