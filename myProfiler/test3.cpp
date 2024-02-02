#include <bits/stdc++.h>

#define TIMER 1

#if TIMER 
#include "myTimer.h"
using namespace timer;
#else 
#define start();
#define stop();
#define stop(...);
#define checkpoint(...);
#define print();
#define print(...);
#endif

typedef long long ll;

using namespace std;

int main() {
	start();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	checkpoint("start");
	checkpoint("IO");
	map<int, int> matches;
	vector<int> ls;
	int l;
	cin >> l;
	while (l != -1) {
		ls.push_back(l);
		matches[l] = 0;
		cin >> l;
	}
	stop("IO");
	stop("start");

	vector<vector<int>> countOne(32);

	int n = ls.size();
	for (int i=0; i<n; ++i) {
		checkpoint("for loop");
//		cout << "Start loop - " << ls[i] << endl;
		// Loop through all the following to find the number of matches
		
		// Count how many ones this number has
		int numOnes = bitset<32>(ls[i]).count();
//		cout << "numONes: " << numOnes << endl;

		// loop through every number with the same number of ones
		for (int o=-2; o<=2; o++) {
			int num = numOnes + o;
			if (num < 0 || num > countOne.size()) {
				continue;
			}
//			cout << "Look at array " << num << endl;
			int size = countOne[num].size();
//			cout << "size: " << size << endl;
			for (int j=0; j<size; ++j) {
//				cout << ls[i] << " Looks at " << countOne[num][j] << endl;
				// For that number, see if it is 2 bit flip difference
				int r = ls[i] ^ countOne[num][j];
				// If it is, then add to the smaller one occurrecne array thing
				if (bitset<32>(r).count() <= 2) {
//					cout << "They are within 2" << endl;
					++matches[min(ls[i], countOne[num][j])];
				}
			}
		}

		countOne[numOnes].push_back(ls[i]);
	}
	stop("for loop");
	//checkpoint("print output");

	// Loop throuhg the map and print
	for (pair<int, int> match : matches) {
		cout << match.first << ":" << match.second << endl;
	}
	stop("print output");

	stop();
	print();

    return 0;
}
