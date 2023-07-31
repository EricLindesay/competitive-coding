#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

string convertFromDecimal(int &number, int base) {
	string result;
	while (number > 0) {
		result = static_cast<char>(number % base) + result;
		number /= base;
	}
	return result;
}

int convertToDecimal(string &number, map<char, int> &charMap, int base) {
	// a string representing the number in characters up to base94
	int result = 0;
	int j = 0;
	for (int i=number.length()-1; i>-1; i--) {
		result += charMap[number[i]] * pow(base, j++);
	}
	return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	for (int caseNum=1; caseNum < t+1; caseNum++) {
		string num, src, target;
		cin >> num >> src >> target;

		// store a map of character to index
		map<char, int> srcMap;
		for (int j=0; j<src.length(); j++)
			srcMap[src[j]] = j;

		int decimal = convertToDecimal(num, srcMap, src.length());
		string otherBase = convertFromDecimal(decimal, target.length());

		printf("Case #%d: ", caseNum);
		for (int i=0; i<otherBase.length(); i++)
			printf("%c", target[otherBase[i]]);
		printf("\n");
	}

    return 0;
}
