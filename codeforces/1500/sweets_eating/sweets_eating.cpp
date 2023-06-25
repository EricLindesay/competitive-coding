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
	sort(arr.begin(), arr.end());
	cout << "PRINTING: ";
	for (int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (long long i=1; i<n+1; i++) {
		// now we can eat I sweets
		// so the (i-1)*m 'th sweet is the one we want first.	
		// multiply current by i/m or something like that
		long long ans = 0;
		vector<long long> multipliers(i);
		for (long long multi=0; multi<i; multi++) {
			multipliers[multi] = multi/m + 1; 
		}
		reverse(multipliers.begin(), multipliers.end());

		for (long long s=0; s<i; s++) {
			ans += multipliers[s]*arr[s];
		}
		cout << ans << " ";
	}

    return 0;
}
