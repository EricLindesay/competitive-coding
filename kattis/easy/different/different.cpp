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
	ll a, b;
	while (cin >> a >> b) {
		cout << abs(a - b) << endl;
	}

    return 0;
}
