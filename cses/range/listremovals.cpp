#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n;
int s;
vector<pair<bool, int>> t;

void insert(int val, int loc) {
	int index = s-1+loc;
	t[index] = make_pair(0, val);
	while (index > 0) {
		index = (index-1)/2;
		t[index].first = 1;
		t[index].second++;
	}
}

void print() {
	for (int i=0; i<t.size(); i++) {
		cout << "[" << t[i].first << ", " << t[i].second << "]";
	}
	cout << endl;
}

int query(int i) {
	int v = 0;
	if (v > i) {
		return -1;  // you are trying to access out of range
	}

	// If it is only one element, just return that
	if (t[v].first == 0) {
		int val = t[v].second;
		t[v].second = 0;
		return val;
	}

	int is = 0;
	while (t[v].first) {
		t[v].second--;  // we are removing an element so there is one less below this

		// Look at two children
		pair<int, int> l = t[v*2+1];
		pair<int, int> r = t[v*2+2];
		// If they are 0 nodes, choose which node you want
		if (i == 0 && !l.first) {
			if (t[v*2+1].second == 0) {
				t[v*2+2].second = 0;
				return r.second;
			} else {
				t[v*2+1].second = 0;
				return l.second;
			}
		} else if (i == 1 && !r.first) {
			t[v*2+2].second = 0;
			return r.second;
		}

		// If they are 1 nodes, find whether to go left or right
		if (l.first) {
			if (l.second > i) {
				// Go left
				v = v*2+1;
				continue;
			} else {
				// Go right
				v = v*2+2;
				i -= l.second;
				continue;
			}
		}
	}
	
	return -1;  // couldn't find it
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

	// Tree with each node containing how many nodes are below it
	s = pow(2, ceil(log2(n)));
	t.resize(s*2-1, make_pair(1, 0));

	int num;
	for (int i=0; i<n; i++) {
		cin >> num;
		insert(num, i);
		// cout << query(num) << endl;
	}

	for (int i=0; i<n; i++) {
		cin >> num;
		cout << query(num-1) << " ";
	}

    return 0;
}
