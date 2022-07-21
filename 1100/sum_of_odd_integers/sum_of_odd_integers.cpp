#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

	for (int i=0; i<t; i++) {
		long long n,k;
		cin >> n >> k;
		
		if ((n%2==1 && k%2==0) || (n%2==0 && k%2==1)) {
			cout << "NO" << endl;
			continue;
		}
		if (k*k > n) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}


    return 0;
}
