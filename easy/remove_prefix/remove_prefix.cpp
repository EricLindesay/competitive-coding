#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long b() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);

	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;
		a[i] = num;
	}

	vector<long long> sorted(n);
	partial_sort_copy(a.begin(), a.end(), sorted.begin(), sorted.end());
	for (int i=0; i<n-1; i++) {
		if (sorted[i] == sorted[i+1]) {
			b[sorted[i] - 1] = 2;
		}
	}

	for (int i=n-1; i>-1; i--) {
		//cout << a[i] << " ";
		// see if the current value has been seen
		if (b[a[i] - 1] == 1) {
			return i+1;
		} else if (b[a[i] - 1] == 2) {
			b[a[i] - 1]--;
		}
	}
	return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

	for (long long i=0; i<t; i++) {
		cout << b() << "\n";
	}
    return 0;
}
