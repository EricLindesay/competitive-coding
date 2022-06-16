#include <iostream>

using namespace std;

int main() {
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	int price;
	printf("%d, %f\n", a, (float) b/m);
	
	if (a <= b/m) { // Just use one way tickets
		price = n*a;
		printf("a");
	} else {
		price = (n/m)*b;
		// Now we need to find whether we should buy another multi pass or not.
		if (n%m > 0) {
			if (b < a) {  // the price for a multi ticket is still better
				price += b;
			} else {
				price += a;
			}
		}
	}

	printf("%d", price);

	return 0;
}
