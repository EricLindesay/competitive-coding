#include <iostream>
#include <cmath>

using namespace std;


long long sum_of_digits(long long n) {
	long long sum = 0;
	while (n > 0) {
		sum += n%10;
		n = n/10;
	}	
	return sum;
}

long long decrease_sum_of_digits() {
	long long n, s, moves=0;
	long long dig = 0;
	cin >> n >> s;
	long long sum_digs = sum_of_digits(n);
	while (sum_digs > s) {
		long long mult_of_ten = pow(10, dig+1);		
		dig++;
		if (n%mult_of_ten == 0)  // if the current digit is a zero, then move to the next
			continue;
		long long diff = mult_of_ten - n%mult_of_ten;
		long long temp_n = n/mult_of_ten;
		sum_digs -= (n/(mult_of_ten/10))%10;
		sum_digs++;
		while (temp_n%10 == 9) {
			temp_n /= 10;
			sum_digs -= 9;
			dig++;
		}
		n += diff;
		moves += diff;
	}
	return moves;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

	for (int i=0; i<t; i++) {
		cout << decrease_sum_of_digits() << endl;
	}

    return 0;
}
