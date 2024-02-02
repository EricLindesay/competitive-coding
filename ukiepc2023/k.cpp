#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool is_cycle(map<int, vector<int>> &info, int a, int b) {
	// we want to see if B is dependent on A
	// b is dependent on A if b is in the list for a, or is in one of the "child" lists
	if (info.count(a) == 0) {
		return false;
	}
	vector<int> listForA = info[a];
	for (int i=0; i<listForA.size(); i++) {
		// Is this b? It is? Return true
		if (listForA[i] == b) {
			return true;
		}

		if (is_cycle(info, listForA[i], b)) {
			return true;
		}
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	map<int, vector<int>> info;
	bool is_cyclic = false;
	while (m > 0) {
		m--;
		int a, b;
		cin >> a >> b;
		bool this_cycle = is_cycle(info, b, a);
		is_cyclic = is_cyclic || this_cycle;

		if (!this_cycle) {  
			// don't add cyclic dependencies or the recursion will loop forever
			info[a].push_back(b);
		}
		// See if b is already dependant on a
		// recursviely look through the map to find dependancy
		// if it is then cyclic
	}

    return 0;
}
