#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;

	n--;  // decrease n by one because we are using that value in all of the calculations
	long long factor = n*(n+1)/2;
	factor++;  // include the n from the final button input

	long long constant = n*(n+1)*(2*n+1)/6;
	
	cout << factor*(n+1) - constant << endl;

    return 0;
}
