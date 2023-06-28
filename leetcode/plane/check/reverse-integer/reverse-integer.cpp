#include <cstdint>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
		int32_t reversed = 0;
		int sign = x / abs(x);
		while (x != 0) {
			int digit = x % 10;
			x /= 10;
			// make sure it doesn't go out of the 32 bit integer range
			if (sign > 0 && reversed > (INT32_MAX - digit) / 10) {
				return 0;
			}
			if (sign < 0 && reversed < (INT32_MIN - digit) / 10) {
				return 0;
			}
			reversed *= 10;
			reversed += digit;
		}
		return reversed;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().reverse(123) << endl;
	cout << Solution().reverse(-123) << endl;
	cout << Solution().reverse(120) << endl;
	cout << "INT_MAX: " << Solution().reverse(2147483647) << endl;
	cout << "INT_MAX: " << Solution().reverse(147483647) << endl;
	cout << "INT_MIN: " << Solution().reverse(-2147483648) << endl;
	cout << endl << "Expected 321 -321 21" << endl;

    return 0;
}
