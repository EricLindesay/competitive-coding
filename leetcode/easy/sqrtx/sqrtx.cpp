#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		int num = 1;
		int subtractions = 0;

        // Subtract odd numbers from it as much as possible
		while (x > 0) {
			x -= num;
			num += 2;
			subtractions++;
		}

		if (x < 0) {
			subtractions--;
		}
		return subtractions;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int x;
	cin >> x;
	cout << Solution().mySqrt(x) << endl;

    return 0;
}
