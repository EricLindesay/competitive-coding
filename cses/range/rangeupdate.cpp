#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class SegTree {
	public:
		SegTree(int n) {
			initialSize = pow(2, ceil(log2(n)));
			size = initialSize*2-1;
			data = vector<ll>(size, 0);
		}

		void init(int val, int loc) {
			data[loc+initialSize-1] = val;
		}

		void update(int val, int l, int r) {
			update(0, 0, initialSize-1, val, l, r);
		}

		void update(int v, int tl, int tr, int val, int l, int r) {
			if (l > r) return;

			if (l == tl && r == tr) {
				data[v] += val;
				return;
			}

			int tm = (tl+tr)/2;
			update(v*2+1, tl, tm, val, l, min(r, tm));
			update(v*2+2, tm+1, tr, val, max(l, tm+1), r);
		}

		ll query(int k) {
			int index = initialSize+k-1;
			ll s = data[index];
			while (index > 0) {
				index = (index-1)/2;
				s += data[index];
			}
			return s;
		}

		void print() {
			for (ll &i : data) {
				cout << i << " ";
			}
			cout << endl;
		}
	private:
		int initialSize;
		int size;
		vector<ll> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
	cin >> n >> q;

	SegTree st(n);
	int val;
	for (int i=0; i<n; i++) {
		cin >> val;
		st.init(val, i);
	}

	int type, a, b, c;
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> a >> b >> c;
			st.update(c, a-1, b-1);
		} else {
			cin >> a;
			cout << st.query(a-1) << endl;
		}
	}

    return 0;
}
