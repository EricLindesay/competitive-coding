#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
	if (n < 100) {  // edge case for 0
		cout << 99 << endl;
		return 0;
	}
	if (n % 100 >= 49)  // round up
		cout << n/100 * 100 + 99  << endl;
	else  // round down
		cout << n/100 * 100 - 1 << endl;

    return 0;
}
