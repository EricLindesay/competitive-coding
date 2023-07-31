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
    ll t;
    cin >> t;

	// Just manually compute all the different values. There are only 24 anyway

	map<int, string> valid;
	valid[-60] = "4 - 4 * 4 * 4 = -60";
	valid[-16] = "4 - 4 - 4 * 4 = -16";
	valid[-15] = "4 / 4 - 4 * 4 = -15";
	valid[-8] = "4 + 4 - 4 * 4 = -8";
	valid[-7] = "4 / 4 - 4 - 4 = -7";
	valid[-4] = "4 / 4 / 4 - 4 = -4";
	valid[-1] = "4 - 4 - 4 / 4 = -1";
	valid[0] = "4 * 4 - 4 * 4 = 0";
	valid[1] = "4 - 4 + 4 / 4 = 1";
	valid[2] = "4 / 4 + 4 / 4 = 2";
	valid[4] = "4 + 4 / 4 / 4 = 4";
	valid[7] = "4 + 4 - 4 / 4 = 7";
	valid[8] = "4 + 4 + 4 - 4 = 8";
	valid[9] = "4 + 4 + 4 / 4 = 9";
	valid[15] = "4 * 4 - 4 / 4 = 15";
	valid[16] = "4 + 4 + 4 + 4 = 16";
	valid[17] = "4 * 4 + 4 / 4 = 17";
	valid[24] = "4 + 4 + 4 * 4 = 24";
	valid[32] = "4 * 4 + 4 * 4 = 32";
	valid[60] = "4 * 4 * 4 - 4 = 60";
	valid[68] = "4 + 4 * 4 * 4 = 68";
	valid[256] = "4 * 4 * 4 * 4 = 256";
	
	while (t--) {
		int n;
		cin >> n;
		if (!valid.count(n)) { // if it isn't there then oh well
			cout << "no solution" << endl;
		} else {
			// print the solution
			cout << valid[n] << endl;
		}
	}

    return 0;
}
