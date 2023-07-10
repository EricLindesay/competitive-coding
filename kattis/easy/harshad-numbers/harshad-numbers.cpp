#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

bool isHarshadNumber(int n) {
	int count = 0;
	int num = n;
	while (n > 0) {
		count += n%10;
		n /= 10;
	}
	return num % count == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	while (true) {
		if (isHarshadNumber(n)) {
			break;
		}
		n++;
	}
	printf("%d\n", n); 

    return 0;
}
