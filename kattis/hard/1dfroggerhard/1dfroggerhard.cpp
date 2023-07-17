#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <sstream>
#include <iterator>

typedef long long ll;

using namespace std;

map<string, int> memory;
map<int, vector<int>> pointedToBy;  // map of index: vector of indexes. The indexes which point to that value after 1 hop	

string hashf(int i, vector<int> &seen) {
	string key = to_string(i) + ","; 
	stringstream result;
	copy(seen.begin(), seen.end(), ostream_iterator<int>(result, ","));
	return key.append(result.str());
}

int recursion(int i, vector<int> &seen) {
	string hashResult = hashf(i, seen);
	auto t = memory.find(hashResult);
	if (t != memory.end())
		return t->second;

	if (seen[i] == 1)
		return 0;

	seen[i] = 1;
	int count = 1;
	for (int ind : pointedToBy[i]) {  // for every index, find how many it points to
		int out = recursion(ind, seen);
		if (out > 0) {
			count += out;
		}
	}

	memory[hashResult] = count;

	return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
    cin >> n;

	vector<int> numbers(n), seen(n, 0);

	// read in the numbers
	for (int i=0; i<n; i++) {
		int num;
		cin >> num;

		if (i + num >= 0 && i + num < n)
			pointedToBy[i+num].push_back(i);
	}

	int count = 0;
	for (int i=0; i<n; i++) {
		count += recursion(i, seen);
		fill(seen.begin(), seen.end(), 0);
	}
	cout << count << endl;

    return 0;
}
