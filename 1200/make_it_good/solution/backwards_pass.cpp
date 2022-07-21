#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


long long make_it_good(long long n, vector<long long> a) {
	bool ascending = true;
	for (long long i=n-1; i>0; --i) {
		if (ascending && a[i] > a[i-1]) {  // it stops ascending at ind i
			// now we need to look for descending.
			ascending = false;
		}
		else if (!ascending && a[i] < a[i-1]) {
			return i;
		}
	}
	
	return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
	while (t-- > 0) {
		long long n;
		cin >> n;
		vector<long long> a(n);
		for (long long i=0; i<n; i++) {
			cin >> a[i];	
		}
		cout << make_it_good(n, a) << endl;
	}

    return 0;
}
