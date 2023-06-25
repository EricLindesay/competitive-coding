#include <iostream>
#include <vector>

using namespace std;

bool is_good(int n, vector<int> a) {
	for (int i=0; i<n; i++) {
		
	}
	return false;
}


int make_it_good(int n, vector<int> a) {
	cout << n << ": ";
	for (int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << is_good(n, a) << endl;
	return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];	
		}
		cout << make_it_good(n, a) << endl;
	}

    return 0;
}
