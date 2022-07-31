#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, l;
    cin >> n >> l;
	vector<long long> arr(n);

	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;
		arr[i] = num;
	}
	sort(arr.begin(), arr.end());

	// distance from 0 to the first one
	long long max_dist = arr[0]*2;

	for (int i=0; i<n-1; i++) {
		long long dist = arr[i+1]-arr[i];
		if (dist > max_dist) {
			max_dist = dist;
		}
	}

	long long final_dist = (l-arr[n-1])*2;
	if (final_dist > max_dist) {
		max_dist = final_dist;
	}
	printf("%f", (double) max_dist/2);

    return 0;
}
