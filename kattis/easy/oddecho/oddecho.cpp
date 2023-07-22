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
    ll n;
    cin >> n;
	int i = 0;
	while (n--) {
		string word;
		cin >> word;
		if (i++%2 == 0)
			cout << word << endl;
	}

    return 0;
}
