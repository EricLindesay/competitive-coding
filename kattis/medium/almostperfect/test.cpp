#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

typedef long long ll;

using namespace std;

vector<int> getPrimeFactors(ll n) {
	vector<int> decomposition;
	decomposition.push_back(1);

	// divide by 2 as much as possible
	while (n % 2 == 0) {
		decomposition.push_back(2);
		n /= 2;
	}

	// divide by remaining odd numbers
	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			decomposition.push_back(i);
			n /= i;
		}
	}

	// this only happens if n itself is prime
	if (n > 2)
		decomposition.push_back(n);

	return decomposition;
}

map<int, int> getPrimeFactorsMap(ll n) {
	map<int, int> decomposition;

	// divide by 2 as much as possible
	if (n % 2 == 0)
		decomposition[2] = 0;

	while (n % 2 == 0) {
		decomposition[2]++;
		n /= 2;
	}

	// divide by remaining odd numbers
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			decomposition[i] = 0;

		while (n % i == 0) {
			decomposition[i]++;
			n /= i;
		}
	}

	// this only happens if n itself is prime
	if (n > 2)
		decomposition[n] = 1;

	return decomposition;
}

void comb(int K, vector<int> decomposition, ll &sum)
{
	map<int, int> seen;
	int N = decomposition.size();

    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
		int product = 1;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) product *= decomposition[i]; 
        }
		sum += product;
		seen[product] = 1;
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

ll sumOfFactors(vector<int> decomposition) {
	ll sum = 0;
	for (int i=1; i<decomposition.size() - 1; i++) {
		comb(i, decomposition, sum);
	}
	return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll num;

	while (cin >> num) {  // this a "read until EOF" one
		vector<int> decomposition = getPrimeFactors(num);

		for (int i=0; i<decomposition.size(); i++) {
			cout << decomposition[i] << " ";
		}
		cout << endl;

		ll sum = sumOfFactors(decomposition);
		cout << sum << endl;
		cout << num;
		if (sum == num) {
			cout << " perfect";
		} else if (abs(sum - num) <= 2) {
			cout << " almost perfect";
		} else {
			cout << " not perfect";
		}
		cout << endl;
	}

    return 0;
}
