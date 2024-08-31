#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
class SegmentTree {
	public:
		SegmentTree(int size) {
			int next = pow(2, ceil(log2(size)));
			size = next*2 - 1;
			initialSize = next;
			data = vector<ll>(size, 0);
		}
 
		void init(vector<ll> values) {
			copy(values.begin(), values.end(), data.begin()+initialSize-1);
			int start = initialSize-1;
 
			// Propagate upwards
			for (int i=0; i<values.size(); i++) {
				start = initialSize-1+i;
				int index = start;
				while (index > 0) {
					index = (index-1)/2;
					data[index] += data[start];
				}
			}
		}
 
		ll sum(int l, int r) {
			return sum(0, 0, initialSize-1, l, r);
		}
 
		ll sum(int v, int tl, int tr, int l, int r) {
			if (v < 0) return 0;
			if (l > r)
				return 0;
			if (l == tl && r == tr) {
				return data[v];
			}
			int tm = (tl + tr) / 2;
			if (l < tm && r <= tm) {
				// Just look at the lower path
				return sum(v*2+1, tl, tm, l, r);
			} else if (l > tm && r > tm) {
				// Look at higher
				return sum(v*2+2, tm+1, tr, l, r);
			} else {
				// Look at both paths
				ll a = sum(v*2+2, tm+1, tr, tm+1, r);
				ll b = sum(v*2+1, tl, tm, l, tm);
				return a+b;
			}
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
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
 
	SegmentTree st(n);
	vector<ll> ns(n);
	for (ll &i : ns) {
		cin >> i;
	}
 
	st.init(ns);
 
	int l, r;
	while (q--) {
		cin >> l >> r;
		cout << st.sum(l-1, r-1) << endl;
	}
 
    return 0;
}
