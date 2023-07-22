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
	string date;
	cin >> date;

	int day;
	cin >> day;

	if ((date == "OCT" && day == 31) || (date == "DEC" && day == 25)) {
		cout << "yup" << endl;
	} else {
		cout << "nope" << endl;
	}

    return 0;
}
