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
	double A, P;
	cin >> A >> P;

	double max_area = (P * P) / (4 * M_PI);
	if (A <= max_area) {
		cout << "Diablo is happy!";
	} else {
		cout << "Need more materials!";
	}

    return 0;
}
