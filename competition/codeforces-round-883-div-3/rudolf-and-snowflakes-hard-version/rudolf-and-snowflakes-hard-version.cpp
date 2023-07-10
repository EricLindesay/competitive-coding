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
		ll n;
		cin >> n;

		double k = 2 - 1.0/n;
		double t = 1.0/n;

		double r;
		if (modf(t, &r) == 0 && t < 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

    return 0;
}
