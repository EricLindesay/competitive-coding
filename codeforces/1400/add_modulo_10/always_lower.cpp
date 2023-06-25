#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool not_all_equal(vector<long long> a) {
	for (long long i=0; i<a.size()-1; i++) {
		if (a[i] != a[i+1]) return true;
	}
	return false;
}

string e() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	
	long long lowest_five = -1;
	long long lowest_ten = -1;
	long long tens = 0;
	long long fives = 0;
	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;
		a[i] = num;
		if (num%10 == 0) {
			tens++;
			if (num < lowest_ten || lowest_ten == -1) {
				lowest_ten = num;
			}
		} else if (num%10 == 5) {
			fives++;
			if (num < lowest_five || lowest_five == -1) {
				lowest_five = num;
			}
		}
	}

	if ((tens+fives > 0 && tens+fives < n) || (lowest_ten < lowest_five) || (tens == n && not_all_equal(a))) {
		return "No";
	}
	if (tens > 0) {
		// all the tens must be the same
		long long ten = -1;
		for (int i=0; i<n; i++) {
			if (a[i]%10 == 0) {
				if (ten == -1) {
					ten = a[i];
				} else if (ten != a[i]) {
					return "No";
				}
			}
		}
		// all of the fives must have a difference of 5 from the tens.
		for (int i=0; i<n; i++) {
			if (a[i]%10 == 5) {
				if (ten-a[i] != 5) {
					return "No";
				}
			}
		}
	}

	sort(a.begin(), a.end());
	long long lowest = a[0];
	long long initial_highest = a[n-1];
	while (not_all_equal(a) && lowest < initial_highest+40) {
		a[0] += a[0]%10;
		sort(a.begin(), a.end());
		lowest = a[0];
	}
	if (not_all_equal(a)) {
		return "No";
	}
	return "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

	for (int i=0; i<t; i++) {
		cout << e() << "\n";
	}
    return 0;
}
