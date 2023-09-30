#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


map<int, int> factorials;
int factorial(int n) {
	if (n == 1) 
		return 1;

	if (factorials.count(n))
		return factorials[n];
	
	int f = factorial(n-1) * n;
	factorials[n] = f;
	return f;
}

int choose(int n, int r) {
	int nFact = factorial(n);
	int rFact = factorial(r);
	int nrFact = factorial(n-r);

	return nFact / (nrFact * rFact);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t, n;
	cin >> t >> n;

	while (t--) {
		ll count = 0;

		map<string, int> seen;
		string name, type;
		cin >> name >> type;

		
	}

    return 0;
}
