#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string name, result;
	cin >> name;
	result = name[0];
	int resultSize = 0;
	int nameLength = name.length();
	for (int i=1; i<nameLength; i++) {
		if (name[i] != result[resultSize]) {
			result += name[i];
			++resultSize;
		}
	}
	cout << result;

    return 0;
}
