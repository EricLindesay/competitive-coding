#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	stack<int> children;
	while (k--) {
		string cmd;
		cin >> cmd;
		if (cmd == "undo") {
			int amount;
			cin >> amount;
			// pop those children from the stack
			while (amount--) {
				children.pop();
			}
		} else {
			int dir = stoi(cmd);
			int top;
			if (children.empty())
				top = 0;
			else
				top = children.top(); 
			
			int new_child = top + dir;
			// wrap around the children
			new_child = ((new_child % n) + n) % n;
			children.push(new_child);
		}
	}
	if (children.empty()) {
		cout << 0;
	} else {
		cout << children.top();
	}
    return 0;
}
