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
	int a, b, c, n;
	cin >> a >> b >> c >> n;

	int sum = a + b + c;
	if (a < 1 || b < 1 || c < 1 || n > sum || n < 3) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}

    return 0;
}
