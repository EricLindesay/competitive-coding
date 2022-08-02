#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


string e() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	
	long long a_len = 0;
	bool tens_fives = false;
	long long first_ten = -1;
	long long first_five = -1;
	long long duplicates[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;
		if (num%10 != 0 && num%10 != 5 && !tens_fives) {
			num = num%20;
			while ((num < 10 || num%2 == 1) && num != 0) {
				num += num%10;
				num = num%20;
			}
			if (duplicates[num] == 0) {
				a[a_len++] = num;
				duplicates[num] = 1;
			}
		} else {
			if (!tens_fives && i != 0) {
				return "No";
			}
			tens_fives = true;
			if (num%10 == 0) {
				if (first_ten == -1) {
					first_ten = num;
				} else {
					if (num != first_ten) {  // 30, 50
						return "No";
					}
				}
				if (first_five != -1) {
					if (num-first_five != 5) {
						return "No";
					}
				}
			} else if (num%10 == 5) {
				if (first_five == -1) {
					first_five = num;
				} else {
					if (num != first_five) {
						return "No";
					}
				}
				if (first_ten != -1) {
					if (first_ten-num != 5) {
						return "No";
					}
				}
			} else {  // there have only been tens and fives but this one isn't
				return "No";
			}	
		}
	}

	if (tens_fives) {
		return "Yes";
	}

	if (a_len == 1) {
		return "Yes";
	}

	bool twos = false;
	bool threes = false;
	bool seven = false;
	bool nine = false;
	for (int i=0; i<a_len; i++) {
		if (!twos && !threes && !seven && !nine) {
			if (a[i]%10 == 7) {
				seven = true;
			} else if (a[i]%10 == 9) {
				nine = true;
			} else if (a[i]%10 == 3 || a[i]%10 == 6) {
				threes = true;
			} else {
				twos = true;
			}
		} else {
			if (seven) {
				if (a[i]%10 != 7) {
					return "No"; 
				}
			} else if (nine) { 
				if (a[i]%10 != 9) {
					return "No";
				}
			} else if (threes) { 
				if (a[i]%10 != 3 && a[i]%10 != 6) {
					return "No";
				}
			} else if (twos) {
				if (a[i]%10 != 1 && a[i]%10 != 2 && a[i]%10 != 4 && a[i]%10 != 8) {
					return "No";
				}
			}
		}
	}

	return "Yes";
}

int main() {
    long long t;
    cin >> t;

	for (int i=0; i<t; i++) {
		cout << e() << "\n";
	}
    return 0;
}
