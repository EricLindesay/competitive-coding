#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

bool isSquare(int n)
{
	int root = sqrt(n);
	return n == root * root;
}

int sum_of_squares(int n)
{
	int root = sqrt(n);

	// Case 1 - it's already square
	if (n == root * root)
		return 1;

	// Case 2 - it is the sum of two squares
	for (int i = 0; i <= root; i++)
	{
		// i*i is a square number (trivially), so you need to check whether the alternative is also square
		if (isSquare(n - (i * i)))
			return 2;
	}

	// Case 3 - if it isn't of the form 4^k(8m + 7)
	// Case 4 - if it is of the form 4^k(8m + 7)
	while (n % 4 == 0)
	{ // divide it by 4 as many times as possible
		n /= 4;
	}
	if (n % 8 == 7)
	{
		return 4; // case 4
	}

	return 3; // case 3
}

int main()
{
	cout << sum_of_squares(18) << endl;
	cout << sum_of_squares(17) << endl;
	cout << sum_of_squares(15) << endl;
	cout << sum_of_squares(16) << endl;

	cout << endl
		 << "Expected: 2, 2, 4, 1" << endl;
}
