#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

map<int, int> outputs;

int sum_of_squares(int n)
{
	if (outputs[n])
		return outputs[n];

	vector<int> possible(n + 1, -1);
	possible[0] = 0;
	int root = sqrt(n);

	for (int i = 1; i <= root; i++)
	{ // loop through every square number
		int square = i * i;
		// update the possible vector
		// it isn't just a single coin, you can have multiple of the same coin so repeat this as many times as possible
		for (int j = 0; j <= n - square; j++)
		{
			if (possible[j] >= 0)
			{
				if (possible[j + square] == -1)
				{ // if this number hasn't been seen before
					possible[j + square] = possible[j] + 1;
				}
				else
				{
					possible[j + square] = min(possible[j] + 1, possible[j + square]);
				}
			}
		}
	}
	outputs[n] = possible[n];
	return possible[n];
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
