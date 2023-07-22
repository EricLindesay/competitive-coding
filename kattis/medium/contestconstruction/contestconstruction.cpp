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
    int n, k;
    cin >> n >> k;

	vector<int> problems(n);
	for (int &d : problems)
		cin >> d;

	sort(problems.begin(), problems.end());

    return 0;
}
