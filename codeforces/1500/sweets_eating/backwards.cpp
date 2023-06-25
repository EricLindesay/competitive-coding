#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
	vector<long long> arr(n);

	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;
		arr[i] = num;
	}
	sort(arr.rbegin(), arr.rend());
	cout << "PRINTING: ";
	for (int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (long long i=n-1; i>=0; i--) {
		// now we can eat I sweets
		// so the (i-1)*m 'th sweet is the one we want first.	
		// multiply current by i/m or something like that
		cout << "i: " << i << endl;
		long long ans = 0;
		for (long long s=n; s>i; s--) {
			//cout << s << endl;
			long long ind = s-1;
			//printf("Multiplier %lld on %lld\n", ((i-1)/m-(s/m)+1), arr[s]);
			cout << "ind: " << ind << " " << arr[ind] << endl;
			cout << "multiplier " << ((n-ind+1)/m) << endl;
			cout << "m2 " << (n-i+1)/m << endl;
			long long multiplier = (n-ind+1)/m;
			long long max_multi = (n-i+1)/m;
			cout << "real mult " << max_multi - multiplier + 1 << endl; 
			ans += multiplier * arr[ind];
		}
		cout << endl;
		//cout << ans << " ";
	}

    return 0;
}
