#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <string.h>
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

int getDecimalPlaces(double num) {
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

	double integralPart = 0;
	double fraction = modf(num, &integralPart);
	
	// find how many decimal points there are
	cout << getDecimalPlaces(fraction) << endl;
	return 0;
	// find greatest common denominator of the amounts of paper
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
