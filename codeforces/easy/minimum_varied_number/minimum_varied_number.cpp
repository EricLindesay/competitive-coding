#include <iostream>


using namespace std;

long long c_func() {
	long long n;
	cin >> n;

	long long i = 0;
	long long counter = 1;
	long long num = 0;
	while (n > 0) {
		if (n/(9-i) > 0) {
			num += counter*(9-i);	
			n -= (9-i);
			counter *= 10;
			i++;
		} else {
			num += counter*(n%(9-i));
			break;
		}
	}

	return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

	for (int i=0; i<t; i++) {
		cout << c_func() << "\n";
	}
    return 0;
}
