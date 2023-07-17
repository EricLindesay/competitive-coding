#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>

typedef long long ll;

using namespace std;

#define MAX_N 200000

map<int, int> workingSet;
map<int, int> totalSet;
map<int, set<int>> totalSetFirst;
map<int, set<int>> workingSetFirst;


int hashf(int a, int b) {
	return a * MAX_N + b;
}

pair<int, int> dehash(int hashv) {
	return {hashv / MAX_N, hashv % MAX_N};
}

bool isDuplicate(int first, int second) {
	auto t = workingSet.find(hashf(first, second));
	if (t != workingSet.end())
		return true;

	auto y = totalSet.find(hashf(first, second));
	if (y != totalSet.end())
		return true;

	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
    cin >> n;

	vector<int> numbers(n);

	int count = n;
	int workingSize = 0;
	// read in the numbers
	for (int i=0; i<n; i++) {
		int num;
		cin >> num;

		if (i + num >= 0 && i + num < n) {
			workingSet[hashf(i, i+num)] = 1;
			workingSetFirst[i].emplace(i+num);
			++workingSize;
		}
		totalSet[hashf(i, i)] = 1;  // you are hashable with yourself
		totalSetFirst[i].emplace(i);  // you are hashable with yourself
	}
	count += workingSet.size();

	// for each one in the working set, find how many of them can go to another value.
	// put these other values into the new working set
	// put the workign set into the totalset
	// repeat until the working set is empty
	
	while (workingSet.size() > 0) { map<int, int> tempWorkingSet;
		map<int, set<int>> tempWorkingSetFirst;
		
		// loop through each key in the working set
		for (auto it = workingSet.begin(); it != workingSet.end(); it++) {
			// add it to the total set
			totalSet[it->first] = it->second;

			pair<int, int> value = dehash(it->first);
			// see if there is something with the appropriate end value in the working set OR the total set.
			totalSetFirst[value.first].emplace(value.second);

			auto workingit = workingSetFirst.find(value.second);
			if (workingit != workingSetFirst.end()) {
				// add any offshoots into the temp working set if they aren't already in the working set of total set
				for (int num : workingit->second) {
					int offshootF = value.first;
					int offshootS = num;
					// is the offshoot in either of the sets?
					// if it isn't, add it to temp working set
					// otherwise leave it
					if (!isDuplicate(offshootF, offshootS)) {
						tempWorkingSet[hashf(offshootF, offshootS)] = 1;
						tempWorkingSetFirst[offshootF].emplace(offshootS);
					}
				}
			} else {
				// see if its in the total set
				auto totalit = totalSetFirst.find(value.second);

				if (totalit != totalSetFirst.end()) { 
					for (int num : totalit->second) {
						int offshootF = value.first;
						int offshootS = num;
						// is the offshoot in either of the sets?
						// if it isn't, add it to temp working set
						// otherwise leave it
						if (!isDuplicate(offshootF, offshootS)) {
							tempWorkingSet[hashf(offshootF, offshootS)] = 1;
							tempWorkingSetFirst[offshootF].emplace(offshootS);
						}
					}
				}
			}
		}
		workingSet = tempWorkingSet;
		workingSetFirst = tempWorkingSetFirst;
		count += workingSet.size();
	}
	cout << count << endl;

    return 0;
}
