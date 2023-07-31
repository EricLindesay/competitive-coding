#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

	
int p, a, b, c, d, n;  // put this in global space so that you don't need to pass 6 parameters to the price function. It makes the price function more intuitive imo.

double price(int k) {
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> p >> a >> b >> c >> d >> n;
	
	double firstPrice = price(1);
	double bestDescent = 0;
	double currentHighest = firstPrice;
	double currentLowest = firstPrice;
	for (int i=2; i<n+1; i++) {
		double thisPrice = price(i);
		if (thisPrice > currentHighest) {
			bestDescent = max(bestDescent, currentHighest - currentLowest);
			currentHighest = thisPrice;
			currentLowest = thisPrice;
		} else if (thisPrice < currentLowest) {
			currentLowest = thisPrice;
		}
	}
	bestDescent = max(bestDescent, currentHighest - currentLowest);

	printf("%lf", bestDescent);

    return 0;
}
