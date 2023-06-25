#include <iostream>

using namespace std;

bool is_prime(long long num) {
	if (num == 0 || num == 1) {
		return false;
	}

	for (long long i=2; i<=num/2; ++i) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;

	long long m = 1;
	while (true) {
		if (!is_prime(n*m+1)) {
			cout << m;
			break;
		}
		m++;
	}

    return 0;
}
