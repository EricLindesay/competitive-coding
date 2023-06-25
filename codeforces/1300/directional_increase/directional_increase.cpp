#include <iostream>
#include <vector>

using namespace std;


void directional_increase(long long n) {
	long long sum = 0;
	long long last_non_zero_num = 0;
	for (long long i=0; i<n; i++) {
		long long num;
		cin >> num;
		sum += num;
		if (i == 0 && num < 0) {  // if first digit is negative, it's impossible
			cout << "No" << endl;
			return;
		}
		if (num != 0) {
			last_non_zero_num = num;
		}
	}
	if (last_non_zero_num == 0) {  // it only contains zeros
		cout << "Yes" << endl;
		return;
	}
	if (last_non_zero_num >= 0 || sum != 0) {
		cout << "No" << endl;
		return;
	}
	
	cout << "Yes" << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long t;
	cin >> t;
	for (int i=0; i<t; i++) {
		long long n;
		cin >> n;
		directional_increase(n);
	}
    return 0;
}
