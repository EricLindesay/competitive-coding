#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	
	int price1 = n*a;
	int price2 = 0;
	price2 = (n/m)*b;
	// Now we need to find whether we should buy another multi pass or not.
	if (n%m > 0) {
		if (b < a*(n%m)) {  // the price for a multi ticket is still better
			price2 += b;
		} else {
			price2 += a*(n%m);
		}
	}
	if (n/m*b == 0) {
		price2 = b;
	}

	printf("%d", min({price1, price2}));

	return 0;
}
