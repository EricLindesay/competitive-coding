#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

	map<int, int> money;

	int currentDefault = 0;
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
				if (money.count(i)) 
					cout << money[i] << endl;
				else 
					cout << currentDefault << endl;
				break;
			case 'R':
				cin >> x;
				currentDefault = x;
				money.clear();
		}
	}

    return 0;
}
