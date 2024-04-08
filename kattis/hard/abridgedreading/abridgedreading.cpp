#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
	vector<int> pages(n);  // how many pages per chapter

	for (int &page : pages) {
		cin >> page;
	}

	vector<int> dependencies(n, 0);
	map<int, vector<int>> dependents;

	int a, b;
	while (m--) {
		cin >> a >> b;
		a--;
		b--;  // put them to zero indexing
		// a must be read before b
		dependents[b].push_back(a);
		//dependencies[a] += dependencies[b] + 1;
		// Could have
		// pages[a] += pages[b]
	}

    return 0;
}
