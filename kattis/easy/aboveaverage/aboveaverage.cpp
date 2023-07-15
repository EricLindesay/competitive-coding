#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		double sum = 0;
		double n;
		cin >> n;
		vector<double> grades(n);
		for (int i=0; i<n; i++) {
			double num;
			cin >> num;
			sum += num;
			grades[i] = num;
		}
		double average = sum/n;
		
		double numAboveAverage = 0;
		for (double grade : grades) {
			if (grade > average)
				numAboveAverage++;
		}
		
		double percent = (numAboveAverage / n) * 100;
		printf("%.3lf%\n", percent);
    }

    return 0;
}
