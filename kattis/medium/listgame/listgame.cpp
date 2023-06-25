#include <iostream>

typedef long long ll;

using namespace std;

int number_prime_factors(int n) {
	int ret = 1;

	ll p = 2;
	while (n >= p*p) {
		if (n%p == 0) {
			ret++;
			n = n/p;
		} else p++;
	}

	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
	
	cout << number_prime_factors(n);

    return 0;
}
