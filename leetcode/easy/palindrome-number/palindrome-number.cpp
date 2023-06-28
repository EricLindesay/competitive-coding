#include <iostream>
#include <cmath>

using namespace std;

class Solution {
	
	int numDigits(int x) {
		// Due to the problem description, this will loop at maximum 10 times. (since x <= 2^31 - 1)
		int digits = 0;
		while (x > 0) {
			digits++;
			x /= 10;
		}
		return digits;
	}

public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

		int digits = numDigits(x);

		for (int i=0; i<digits/2; i++) {
			int lower_digit = x % static_cast<int>(pow(10, i+1)) / pow(10, i);
			int upper_digit = x / static_cast<int>(pow(10, digits-i-1)) % 10;
			if (lower_digit != upper_digit)
				return false;
		}

		return true;
    }
};

int main() {
	cout << Solution().isPalindrome(299838992) << endl;
}
