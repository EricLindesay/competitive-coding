#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
	int charToInt(char c) {
		return c-'0';
	}

	void print(vector<int> out) {
		string outStr = "";
		for (int i=out.size() - 1; i >= 0; i--) {
			if (outStr.size() == 0 && out[i] == 0) {  // don't include leading zeros
				continue;
			}
			outStr.push_back('0'+out[i]);
		}
		cout << outStr << endl;
	}

    string multiply(string num1, string num2) {
		vector<int> out(num1.size() + num2.size()+1, 0);
		//  234
		//  435 x

		// to multiply two numbers, do them in reverse order
		for (int i=num2.size() - 1; i >= 0; i--) {
			for (int j=num1.size() - 1; j >= 0; j--) {
				int mult = charToInt(num2[i]) * charToInt(num1[j]);
				cout << num2[i] << "*" << num1[j] << " = " << mult << endl;
				int l1 = out[j+i] + mult%10;
				int l2 = out[j+i+1] + mult/10 + l1%10;
				out[j+i] = l1%10;
				out[j+i+1] = mult/10;
			}
			print(out);
			//out[1] = charToInt(num2[0]) * charToInt(num1[1]);
			//out[2] = charToInt(num2[0]) * charToInt(num1[2]);
		}

		string outStr = "";
		for (int i=out.size() - 1; i >= 0; i--) {
			if (outStr.size() == 0 && out[i] == 0) {  // don't include leading zeros
				continue;
			}
			outStr.push_back('0'+out[i]);
		}

		return outStr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().multiply("123", "456") << endl;

    return 0;
}
