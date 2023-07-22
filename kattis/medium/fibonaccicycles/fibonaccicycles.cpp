#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
	cin >> q;

	while (q--) {
		int k;
		cin >> k;
		vector<int> seen(k, 0);

		int a = 1;
		int b = 1;
		int i = 2;
		int c;
		while (true) {
			c = (a + b) % k;
			a = b;
			b = c;
			if (seen[c])
				break;

			seen[c] = i;
			++i;
		}
		cout << seen[c] << endl;
	}

    return 0;
}
