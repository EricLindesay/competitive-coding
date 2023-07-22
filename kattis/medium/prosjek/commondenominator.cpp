#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

double round(double value, int decimal_places) {
    const double multiplier = pow(10.0, decimal_places);
    return round(value * multiplier) / multiplier;
}

int gcd(int a, int b) {
   if (b == 0)
	   return a;
   return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double num;
    cin >> num;
	vector<int> paper(6, 0);

	double sum = round(num);
	paper[sum]++;
	double amount = 1;

	while (round(sum/amount, 9) != num) {
		if (sum/amount > num) {
			// look at all the smallest ones and pick the best
			int flr = floor(sum/amount);
			int closest = flr;
			double closestAdded = (sum+flr)/(amount+1);
			while (flr--) {
				// if using this number is closer than using the other numbers, use this one instead
				double usingThis = (sum+flr)/(amount+1);
				if (abs(usingThis - num) < abs(closestAdded - num)) {
					closest = flr;
					closestAdded = usingThis;
				}
			}
			paper[closest]++;
			sum += closest;
			amount++;
		} else {
			// look at all the larger ones and pick the best
			int cl = ceil(sum/amount);
			int closest = cl;
			double closestAdded = (sum+cl)/(amount+1);
			while (cl++ < 6) {
				// if using this number is closer than using the other numbers, use this one instead
				double usingThis = (sum+cl)/(amount+1);
				if (abs(usingThis - num) < abs(closestAdded - num)) {
					closest = cl;
					closestAdded = usingThis;
				}
			}
			paper[closest]++;
			sum += closest;
			amount++;
		}
	}
	// find greatest common denominator
	int greatestDivisor = paper[0];
	for (int i=1; i<6; i++) {
		greatestDivisor = gcd(greatestDivisor, paper[i]);
	}

	for (int i=0; i<6; i++) {
		paper[i] /= greatestDivisor;
	}

	for (int i=1; i<6; i++) {
		cout << paper[i] << " ";
	}
	cout << endl;

    return 0;
}
