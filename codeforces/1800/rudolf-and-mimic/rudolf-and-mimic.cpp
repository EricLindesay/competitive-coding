#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll t;
    cin >> t;


	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> numbers(10, vector<int>(0));
		vector<int> previous(10, 0); // stores previous sizes

		for (int i=0; i<5; i++) {
			for (int j=0; j<9; j++) {
				numbers[j].clear();  // clear the numbers for the new round
			}

			// read in the thing
			for (int j=0; j<n; j++) {
				int number;
				cin >> number;
				numbers[number].push_back(j);
			}

			if (i != 0) {  // this isn't valid for the first loop
				// has the mimic changed?
				// count how many of each number there are
				int mimicChanged = -1;
				for (int j=0; j<10; j++) {
					// printf("%d %ld %d\n", j, numbers[j].size(), previous[j]);
					if (numbers[j].size() > previous[j]) {
						mimicChanged = j;
					// 	printf("Mimic changed: %d\n", mimicChanged);
					}
				}
				if (mimicChanged != -1) {  // if the mimic HAS changed
					// remove all indexes other than the mimic
					int numToRemove = n - numbers[mimicChanged].size();
					if (numToRemove > 0) {
						string out = "- "+to_string(numToRemove);
						for (int j=0; j<10; j++) {
							if (j != mimicChanged) {  // we only want to add non-changed
								for (int num : numbers[j]) {
									out += " "+to_string(num+1);
								}
							}
						}
						cout << out << endl;
						cout.flush();
					}
					n -= numToRemove;

					// if there is one left, its the mimic
					if (numbers[mimicChanged].size() == 1) {
						int q;
						cin >> q;  // read in the input so that nothing messes up
						cout << "! 1" << endl;
						cout.flush();
						break;
					}
				} else {  // mimic hasn't changed
					cout << "- 0" << endl;
					cout.flush();
				}
			} else {
				// if the mimic hasn't changed then we need to reset again
				cout << "- 0" << endl;
				cout.flush();
			}

			for (int j=0; j<10; j++) {
				previous[j] = numbers[j].size();
			}
		}
	}

    return 0;
}
