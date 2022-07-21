#include <iostream>
#include <math.h>

using namespace std;


long double logn(long double base, long double x) {
	return log(x)/log(base);
}

bool recursion(long long n, long long a, long long b, int depth=0) {
	cout << "Error when " << n << ":" << a << ":" << b<< ":"<<depth << endl;
	long double lognres = logn(a, n);	
	if (trunc(lognres) == lognres) {  // is it evenly divisible by a?
		return true;
	}
	if ((n-1)%b == 0) {
		return true;
	}
	// recursively check n/a and n-b
	if ((long double) n/a == 0) {  // n is divisible by a
//		cout << "after" << endl;
//		cout << "error in n/a?" << endl;
		if (recursion(n/a, a, b, depth+1))
			return true;
//		cout << "not in n/a" << endl;
	}
	if (n-b > 1) {  // if its < 0, ignore it. If its == 1 it would have already been checked
//		cout << "error in n-b?" << endl;
//		cout << "after" << endl;
		if (recursion(n-b, a, b, depth+1))
			return true;
//		cout << "not in n-b" << endl;
	}

//	cout << "after" << endl;
	return false;
}

void plus_and_multiply() {
	long long n, a, b;
	cin >> n >> a >> b;

	if (recursion(n, a, b)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long long n;
    cin >> n;
	
	while (n-- > 0) {
		plus_and_multiply();
	}

    return 0;
}
