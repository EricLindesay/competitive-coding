#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

	++n;
	int *money = (int *) calloc(0, sizeof(int)*(n+1));

	string cmd;
	int i, x;
	while (q--) {
		cin >> cmd;
		switch (cmd[0]) {  // only check first character since its more efficient then checking entire string
			case 'S':
				cin >> i >> x;
				money[i] = x;
				break;
			case 'P':
				cin >> i;
				cout << money[i] << endl;
				break;
			case 'R':
				cin >> x;
				delete money;
				money = (int *) calloc(x, sizeof(int)*(n+1));
		}
	}

    return 0;
}
