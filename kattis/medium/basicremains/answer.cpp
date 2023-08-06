#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int b;
	string p, m;
	cin >> b;
	while (b != 0) {
		cin >> p >> m;

		// convert the mod value to a number
		ll mod = 0;
		for (char &val : m) {
			mod *= b;
			mod += val - '0';
		}

		// convert the big value to a number, using mod with the mod value each time
		ll bigval = 0;
		for (char &val : p) {
			bigval *= b;
			bigval += val - '0';
			bigval %= mod;
		}

		// convert it back to a string
		string ans;
		while (bigval > 0) {
			ans.push_back((bigval % b) + '0');
			bigval /= b;
		}

		// reverse the answer (since the thing above makes it the other way around)
		reverse(ans.begin(), ans.end());

		if (ans.size() == 0) {
			cout << "0" << endl;
		} else {
			cout << ans << endl;
		}

		cin >> b;
	}

    return 0;
}
