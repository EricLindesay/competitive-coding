#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b, c;
    cin >> a >> b >> c;
	
	if (a == 1 || b == 1 || c == 1) {
		long long num1 = (a+b)*c;
		long long num2 = a*(b+c);
		long long num3 = a+b+c;
		long long num4 = a+(b*c);
		long long num5 = (a*b)+c;
		cout << max({num1, num2, num3, num4, num5});
	} else {
		cout << a*b*c;
	}
    return 0;
}
