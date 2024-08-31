#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class SegmentTree {
public:
	SegmentTree(int n) {
		non_round = n;
		int next = pow(2, ceil(log2(n)));
		size = 2*next-1; 
		initialSize = next;
		data = vector<ll>(size, INT_MAX);
	}

	void init(vector<ll> &n) {
		copy(n.begin(), n.end(), data.begin()+initialSize-1);

		for (int i=0; i<n.size(); i++) {
			int start = initialSize+i-1;
			int index = initialSize+i-1;
			while (index > 0) {
				index = (index-1)/2;
				data[index] = std::min(data[index], data[start]);
			}
		}
	}

	ll min(int l, int r) {
		return min(0, 0, initialSize-1, l, r);
	}

	ll min(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return INT_MAX;
		}
		if (l == tl && r == tr) {
			return data[v];
		}
		int tm = (tl + tr) / 2;
		if (l < tm && r <= tm) {
			return min(v*2+1, tl, tm, l, r);
		}
		if (l > tm && r > tm) {
			return min(v*2+2, tm+1, tr, l, r);
		}
		
		int a = min(v*2+1, tl, tm, l, tm);
		int b = min(v*2+2, tm+1, tr, tm+1, r);
		return std::min(a, b);
	}

	void print() {
		for (ll &i : data) {
			cout << i << " ";
		}
		cout << endl;
	}

private:
	int size;
	int initialSize;
	vector<ll> data;
	int non_round;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	SegmentTree st(n);

	vector<ll> ns(n);
	for (ll &i: ns) {
		cin >> i;
	}
	st.init(ns);

	int l, r;
	while (q--) {
		cin >> l >> r;
		cout << st.min(l-1, r-1) << endl;
	}

    return 0;
}
