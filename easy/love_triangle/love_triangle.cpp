#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
	vector<long long> f(n);

	for (long long i=0; i<n; i++) {
		long long num;
		cin >> num;
		f[i] = num;
	}

	for (long long i=0; i<n; i++) {
		long long ind1 = f[i]-1;
		if (i == ind1) {
			continue;
		}
		long long ind2 = f[ind1]-1;
		if (i == ind2) {
			continue;
		}
		if (i == f[ind2]-1) {
			cout << "YES";
			return 0;
		}	
	}

	cout << "NO";
    return 0;
}
