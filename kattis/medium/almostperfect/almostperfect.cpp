#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll num;

	while (cin >> num) {  // this a "read until EOF" one
		ll divisorSum = 1;
		for (int i=2; i*i <= num; i++) {
			if (num % i == 0) {
				divisorSum += i;
				if (num/i != i) {
					divisorSum += num/i;
				}
			}
		}
		if (divisorSum == num) {
			cout << num << " perfect" << endl;
		} else if (abs(num - divisorSum) <= 2) {
			cout << num << " almost perfect" << endl;
		} else {
			cout << num << " not perfect" << endl;
		}
	}

    return 0;
}
