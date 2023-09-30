#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<int> seen(42, 0);

	int n = 10;
	int mod = 42;
	int distinct = 0;
	while (n--) {
		int num;
		cin >> num;
		
		if (seen[num%mod]) {
			continue;
		} else {
			seen[num%mod] = 1;
			distinct++;
		}
	}

	cout << distinct;

    return 0;
}
