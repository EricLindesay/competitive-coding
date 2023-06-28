#include <iostream>
#include <vector>
#include <limits.h>

typedef long long ll;

using namespace std;

class Solution
{
public:
	int myAtoi(string s)
	{
		bool foundStart = false;
		int num = 0;
		int sign = 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (!foundStart)
			{
				if (s[i] == ' ')
					continue; // ignore leading whitespace

				if (s[i] == '-')
				{
					sign = -1;
					continue;
				}

				if (s[i] == '+')
				{
					sign = 1;
					continue;
				}

				if (!isdigit(s[i])) // if you find a letter before finding any numbers, return 0
					return 0;
				else
					foundStart = true;
			}
			// Note this is not an else
			if (foundStart)
			{
				if (!isdigit(s[i]))
					break;

				int newNum = s[i] - '0';
				if (sign > 0 && num > (INT32_MAX - newNum) / 10)
				{
					return INT32_MAX; // clamp it to int max if it goes too high
				}
				if (sign < 0 && num * sign < (INT32_MIN - newNum) / 10)
				{
					return INT32_MIN;
				}
				num *= 10;
				num += newNum;
			}
		}

		return num * sign;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << Solution().myAtoi("42") << endl;
	cout << Solution().myAtoi("   -42") << endl;
	cout << Solution().myAtoi("4193 with words") << endl;
	cout << Solution().myAtoi("ith words") << endl;
	cout << Solution().myAtoi("ith 823 words") << endl;

	return 0;
}
