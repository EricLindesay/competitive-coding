#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

map<float, bool> cache;

bool is_sqrt(float n) {
	if (cache[n])
		return cache[n];
	
	int root = sqrt(n);
	cache[n] = ((root * root) == n);
	return cache[n];
}

int recursion(int n, int t) {
	printf("%d %d\n", n, t);
	if (is_sqrt(t)) {
		printf("\t1\n");
		return 1;
	}
	if (is_sqrt(t/2.0)) {
		printf("\t2\n");
		return 2;
	}
	if (is_sqrt(t/3.0)) {
		printf("\t3\n");
		return 3;
	}

	int first = recursion(n, t-1);
	int second = recursion(t, n-t);
	printf("\treturn %d + %d\n", first, second);
	return first + second;
}

int sum_of_squares(int n) {
    return recursion(n, n);
}

int main() {
	cout << sum_of_squares(19) << endl;
	cout << sum_of_squares(18) << endl;
	cout << sum_of_squares(17) << endl;
	cout << sum_of_squares(16) << endl;
	cout << sum_of_squares(15) << endl;
	
	cout << endl << "Expected: 3, 2, 2, 1, 4" << endl;
}
