#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class SegTree {
	public:
		SegTree(int size) {
			this->size = pow(2, ceil(log2(size)));
			data.resize(this->size*2);
		}

		void insert(int loc, int val) {
			int pos = loc+size;
			data[pos] = val;
			while (pos > 0) {
				pos = (pos)/2;
				data[pos] = max(data[pos*2], data[pos*2+1]);
			}
		}

		void update(int pos, int val) {
			data[pos] -= val;
			while (pos > 0) {
				pos = (pos)/2;
				data[pos] = max(data[pos*2], data[pos*2+1]);
			}

		}

		int query(int val) {
			// Go through and find the lowest value which is GE val using BS
			// Then update it by subtracting a certain amount
			int node = 1;
			
			if (data[1] < val) {
				return -1;
			}

			while (true) {
				// Get left and right. 
				if (node*2+1 > data.size()) {
					// We are at a leaf node now, this is the node to update
					break;
				}
				int l = node*2;
				int r = node*2+1;
				if (data[l] >= val) {
					// go left
					node = l;
				} else {
					// go right
					node = r;
				}
			}
			update(node, val);
			return node-size;
		}

		void print() {
			cout << endl;
			for (ll &v : data) {
				cout << v << " ";
			}
			cout << endl;
		}

	private:
		int size;
		vector<ll> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;

	SegTree st(n);
	int v;
	for (int i=0; i<n; i++) {
		cin >> v;
		st.insert(i, v);
	}	
	
	while (m--) {
		cin >> v;
		cout << st.query(v)+1 << " ";
	}
	cout << endl;

    return 0;
}
