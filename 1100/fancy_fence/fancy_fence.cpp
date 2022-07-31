#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
	for (int i=0; i<t; i++) {
		long long a;
		cin >> a;
		double n = (double) 360/(180-a);
		if ((int) n == n) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
