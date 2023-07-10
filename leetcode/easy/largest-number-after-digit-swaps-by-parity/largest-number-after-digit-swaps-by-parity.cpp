#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

typedef long long ll;

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
		int numLength = log10(num) + 1;
        vector<bool> digitOdd(numLength);  // same size as num length eventually
		priority_queue<int> evens;
		priority_queue<int> odds;

		// Loop through the number
		int i=0;
		while (num > 0) {
			int digit = num % 10;
			num /= 10;

			if (digit % 2) {
				digitOdd[i] = true;
				odds.push(digit);
			} else {
				digitOdd[i] = false;
				evens.push(digit);
			}
			i++;
		}

		// Form the new number
		int ret = 0;
		for (int i=digitOdd.size() - 1; i>=0; i--) {
			int val;
			if (digitOdd[i]) {
				val = odds.top();
				odds.pop();
			} else {
				val = evens.top();
				evens.pop();
			}
			ret *= 10;
			ret += val;
		}

		return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().largestInteger(1234) << endl;
	cout << Solution().largestInteger(65875) << endl;

    return 0;
}
