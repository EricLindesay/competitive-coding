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
	int a, b;
	cin >> a >> b;
	if (a < b)
		cout << a << " " << b;
	else
		cout << b << " " << a;

    return 0;
}
