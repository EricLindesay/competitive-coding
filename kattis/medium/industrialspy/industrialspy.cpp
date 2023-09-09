#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool isPrime(int n) {
	// Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		string num;
		cin >> num;

		// Find every permutation of the number to see if prime
	}

    return 0;
}
