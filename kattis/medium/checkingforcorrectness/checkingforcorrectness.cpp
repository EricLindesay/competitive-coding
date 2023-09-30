#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

int addition(ll a, ll b) {
	// we only care about the last 4 digits
	ll out = a + b;
	return (a + b) % 10000;
}

int multiplication(ll a, ll b) {
	// get the last four digits of both of them
	int lastA = a % 10000;
	int lastB = b % 10000;

	// Multiply them together then get the last 4 digits
	return (lastA * lastB) % 10000;
}

int exponentiation(ll a, ll b) {
	int lastA = a % 10000;
	int lastB = b % 10000;

	int out = lastA;
	// I don't think you can do the last 4 digits here, I think you have to use the entire exponent.
	// You might have to find a loop and then from that loop you can work out where the exponet comes into play
	map<int, int> seen;  // the last four digits : the index in loop
	vector<int> loop;
	loop.push_back(out);
	seen[out] = 0;
	b--;
	while (b >= 1) {
		out = multiplication(out, lastA);
		if (seen.count(out)) {
			// its the start of the loop so work out the rest manually
			ll loop_size = loop.size() - seen[out];
			ll t = (seen[out] + b) % loop_size;
			if (t == 0) {
				t = loop.size();
			}
			out = loop[t - 1];
			break;
		}
		seen[out] = loop.size();
		loop.push_back(out);
		b--;
	}
	return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll a, b;
	char op;

	while (cin >> a >> op >> b) {
		switch (op) {
			case '+':
				cout << addition(a, b) << endl;
				break;
			case '*':
				cout << multiplication(a, b) << endl;
				break;
			case '^':
				cout << exponentiation(a, b) << endl;
				break;
		}
	}

    return 0;
}
