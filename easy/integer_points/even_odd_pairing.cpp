#include <iostream>

using namespace std;


long long integer_points() {
	// read in inputs.
	long long n;
	cin >> n;
	long long even_odd[] = {0, 0};
	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;
		even_odd[num%2]++;
	}

	long long m;
	cin >> m;
	long long ans = 0;
	for (int i=0; i<m; i++) {
		long long num;
		cin >> num;
		ans += even_odd[num%2];
	}

	return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
	
	for (int i=0; i<t; i++) {
		cout << integer_points() << endl;
	}

    return 0;
}
