#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class SegmentTree {
	public:
		SegmentTree(int n) {
			initialSize = pow(2, ceil(log2(n)));
			size = initialSize*2-1;
			data = vector<ll>(size, 0);  // Might have to change the default
		}

		void update(int val, int loc) {
			int original = data[initialSize+loc-1];  // Choose appropriate function here, this is sum
			data[initialSize+loc-1] = val;

			int index = initialSize+loc-1;
			while (index > 0) {
				index = (index-1)/2;
				data[index] ^= original;  // Choose appropriate function here, this is sum
				data[index] ^= val;
			}
		}

		void print() {
			for (ll &i : data) {
				cout << i << " ";
			}
			cout << endl;
		}

		ll query(int l, int r) {
			return query(0, 0, initialSize-1, l, r);
		}

		ll query(int v, int tl, int tr, int l, int r) {
			if (l > r)
				return 0;  // Might have to change this return value for different types
			if (l == tl && r == tr) 
				return data[v];

			int tm = (tl+tr)/2;
			if (l < tm && r <= tm)
				return query(v*2+1, tl, tm, l, r);
			if (r > tm && l > tm)
				return query(v*2+2, tm+1, tr, l, r);

			// Choose appropriate function here, this is sum
			return query(v*2+1, tl, tm, l, tm) ^ query(v*2+2, tm+1, tr, tm+1, r);
		}
	
	private:
		vector<ll> data;
		int size;
		int initialSize;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, q;
	cin >> n >> q;

	SegmentTree st(n);
	int val;
	for (int i=0; i<n; i++) {
		cin >> val;
		st.update(val, i);
	}

	int type, a, b;
	while (q--) {
		cin >> a >> b;
		cout << st.query(a-1, b-1) << endl;
	}

    return 0;
}
