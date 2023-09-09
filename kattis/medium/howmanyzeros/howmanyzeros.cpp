#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m, n;
    
	while (cin >> m >> n && m != -1 && n != -1) {
		int diff = n - m;

		int output = 0;
		// find out how many 1000s away you are and 100s and 10s
		// In numbers 1 -> 1000 there are (1 -> 100) * 10 + 1
		// 1 -> 10 = 1
		// 1 -> 100 = 11
		// 100 -> 200 = 10 + 10 + 2 = 22
		// 1 -> 1000 = 111
		// 1000 -> 2000 = 20+20+10+220+3 = 300 
		// doesn't work currently

		int current = 0;
		while (diff > 0) {
			int digit = diff % 10;
			diff /= 10;

			output += current * digit;
			current = (current * 10) + 1;
		}

		cout << output << endl;
		// 1234  2567
		// 1333
		// 3 + 6 + 
	}

    return 0;
}
