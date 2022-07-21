#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;

	long long sum = 0;
	long long last_non_zero = 0;
	for (long long i=0; i<n; i++) {
		long long num;
		cin >> num;
		sum += num;
		if (i == 0 && num < 0) {
			cout << "No";
			return 0;
		}
		if (num != 0) {
			last_non_zero = num;
		}
	}
	if (last_non_zero >= 0 || sum != 0) {
		cout << "No";
		return 0;
	}
	
	cout << "Yes";
    return 0;
}
