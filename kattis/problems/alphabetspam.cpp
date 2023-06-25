#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
    cin >> s;

	double caps, lower, symbol, white;

	for (char c : s) {
		if (c >= 65 && c <= 90) caps++;
		else if (c >= 97 && c <= 122) lower++;
		else if (c == '_') white++;
		else symbol++;
	}
	ll total = caps+lower+symbol+white;
	caps = caps/total;
	lower = lower/total;
	symbol = symbol/total;
	white = white/total;
	cout << white << endl << lower << endl << caps << endl << symbol;
    return 0;
}
