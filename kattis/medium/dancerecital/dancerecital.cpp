#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int numChanges(string a, string b) {
	int changes = 0;
	map<char, bool> seen;
	for (int i=0; i<a.length(); i++) {
		seen[a[i]] = true;
	}

	for (int i=0; i<b.length(); i++) {
		if (seen.count(b[i])) {
			++changes;
		}
	}
	return changes;
}

void print_list(list<string> order, int quickChanges) {
	list<string>::iterator it = order.begin();
	while (it != order.end()) {
		cout << *it << " ";
		it++;
	}
	cout << ": Value = " << quickChanges;
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

	//map<char, vector<int>> dancers;
	vector<string> routines(n);
	for (int i=0; i<n; i++) {
		cin >> routines[i];
	}

	list<string> order;
	order.push_back(routines[0]);
	int quickChanges = 0;
	for (int i=1; i<n; i++) {
		// Now we need to look where to insert it into the list
		// See what would happen for every possible location we could put it
		// Put it in the best location (the location with the least quick changes as a result)

		string thisRoutine = routines[i];

		// What if we insert it before the first element?		
		list<string>::iterator it = order.begin();
		int start = numChanges(*it, thisRoutine);
		
		list<string>::iterator bestPos = order.begin();
		int changes = INT_MAX;

		string prev = *it;
		++it;
		// What if we insert it between two elements?
		while (it != order.end()) {
			// find the changes between prev and it
			// find the changes between prev and this, and, this and it
			// If the insert results in fewer changes, thats great
			//int prevChanges = numChanges(prev, *it);
			int newChanges = numChanges(prev, thisRoutine) + numChanges(*it, thisRoutine) - numChanges(prev, *it);
			cout << "Inserting " << thisRoutine << " between " << prev << " and " << *it << " results in newChanges = " << newChanges << endl;

			if (newChanges < changes) {
				changes = newChanges;
				bestPos = it;
			}
			prev = *it;
			++it;
		}
		
		// What if we insert it at the end?
		int end = numChanges(prev, thisRoutine);

		// is it best inserting at the end?
		if (start <= changes && start <= end) {
			// insert at end
			order.push_front(thisRoutine);
		} else if (end <= start && end <= changes) {  // is it best inserting in the middle?
			order.push_back(thisRoutine);
		} else {
			// Otherwise, insert at start
			order.insert(bestPos, thisRoutine);
		}
		print_list(order, 4);
	}

	int changes = 0;
	list<string>::iterator it = order.begin();

	string prev = *it;
	++it;
	while (it != order.end()) {
		changes += numChanges(prev, *it);
		prev = *it;
		++it;
	}
	cout << changes;

    return 0;
}
