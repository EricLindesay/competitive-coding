#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

vector<int> solution; // stores the change giving array up to the highest number of visits.

int sum_of_squares(int n)
{
    if (n < solution.size())
        return solution[n];

    int prevSize = solution.size();
    solution.resize(n + 1, -1); // scale up the solution
    solution[0] = 0;
    solution[1] = 1;
    solution[2] = 2;
    solution[3] = 3;

    int root = sqrt(n);
    for (int i = 2; i <= root; i++)
    { // loop through every square number
        int square = i * i;
        // update the possible vector
        // it isn't just a single coin, you can have multiple of the same coin so repeat this as many times as possible
        for (int j = max(prevSize - square + 1, 0); j <= n - square; j++)
        {
            if (solution[j] >= 0)
            {
                if (solution[j + square] == -1)
                { // if this number hasn't been seen before
                    solution[j + square] = solution[j] + 1;
                }
                else
                {
                    solution[j + square] = min(solution[j] + 1, solution[j + square]);
                }
            }
            else
            {
                solution[j] = j; // this is true as you can do it using the number 1
            }
        }
    }
    return solution[n];
}

int main()
{
    cout << sum_of_squares(18) << endl;
    cout << sum_of_squares(17) << endl;
    cout << sum_of_squares(16) << endl;
    cout << sum_of_squares(15) << endl;
    cout << sum_of_squares(113) << endl;

    cout << endl
         << "Expected: 2, 2, 4, 1" << endl;
}
