#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

template<class T>
struct SegmentTree {
	int n;
	vector<T> tree;
	int size;

	SegmentTree(int n) : n(n) { 
		size = 1 << (int) (log2(n)+1);
		tree.resize(2*size-1);  
	}

    private:
        void insert(T v, int ind, int l, int r, int i=0){
            if (l == r && ind == l){
                tree[i] = v;
                return;
            }
            if (l > ind) return;
            if (r < ind) return;

            int mid = (l+r)/2;
            insert(v,ind,l,mid,i*2+1);
            insert(v,ind,mid+1,r,i*2+2);

            tree[i] = tree[i*2+1] + tree[i*2+2];
        }

        long long contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                return tree[i];
            }
            if (cl > r || cr < l) return 0;
            int mid = (cl+cr)/2;
            // merge results
            return contained(l,r,cl,mid,i*2+1) + contained(l,r,mid+1,cr,i*2+2);
        }

    public:
        void insert(int ind, T v) { insert(v,ind,0,n); }

        long long contained(int l, int r) { return contained(l,r,0,n,0); }
};

int tfind(SegmentTree<int> &t, int k, int l, int r) {
	if (l == r) {
		if (t.contained(l, r) == 0) {
			return -1;
		}
		return l;
	}
	int mid = (l+r)/2;
	int lc = t.contained(l, mid);
	if (k < lc) {
		return tfind(t, k, l, mid);
	} else {
		return tfind(t, k-lc, mid+1, r);
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int a;
	SegmentTree<int> t(n);
	for (int i=0; i<n; i++) {
		cin >> a;
		t.insert(i, 1);
	}
	
	int f, s;
	int num_alive = n;
	int pos = 0;
	while (q--) {
		/*
		for (int i=0; i<num_alive; i++) {
			cout << tfind(t, i, 0, n) << " ";
		}
		cout << endl;
		*/
		for (int i=0; i<num_alive; i++) {
			cout << (pos+i) << " ";
		}
		cout << endl;
		for (int i=0; i<num_alive; i++) {
			cout << tfind(t, (pos+i)%num_alive, 0, n) << " ";
		}
		cout << endl;
		cin >> f >> s;
		if (f == 0) {
			// print k'th poorest
			//cout << as[s-1] << endl;
			int poorest = tfind(t, (pos+s-1)%(num_alive), 0, n);
			cout << "OUTPUT: "  << poorest << endl;
		} else {
			cout << "Delete richest" << endl;
			// distribute from richest into s poorest
			// Find the index of richest
			// kill richest
			
			int richest = tfind(t, (pos+num_alive-1)%num_alive, 0, n);
			cout << "Richest: " << richest << endl;
			t.insert(richest, 0);
			num_alive--;
			cout << "Rotate by " << s << endl;
			// now rotate by s
			pos += s;
			cout << "pos is " << pos << endl;
			pos %= num_alive;
		}
		
		/*
		for (int i=0; i<as.size(); i++) {
			cout << as[i].first << "(" << as[i].second << ") ";
		}
		cout << endl;*/
	}

    return 0;
}
