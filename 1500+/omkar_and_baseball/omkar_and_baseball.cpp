#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases-- > 0) {
		int n;
		cin >> n;

		string end;
		getline(cin, end);
		
		vector<long unsigned int> nums;
		string s;
		getline(cin, s);
		istringstream sstr(s);
		long unsigned int num;
		while (sstr >> num) {
			nums.push_back(num);
		}

		long signed int first=-1, last=-1;

		int in_place = 0;
		// for (int i=0; i<(int) nums.size()/2; i++) {
		// 	cout << nums[i] << endl;
		// 	cout << nums[(int) nums.size()-i-1] << endl;
		// 	if (!first) {
		// 		if (i+1 != nums[i]) {
		// 			first = true;	
		// 		}	
		// 	} else {
		// 		if (i+1 == nums[i]) {
		// 			in_place++;
		// 		}
		// 	} 
		// 	if (!last) {
		// 		if ((int) nums.size()-i == nums[(int) nums.size()-i-1]) {
		// 			last = true;
		// 		}
		// 	} else {
		// 		if ((int) nums.size()-i == nums[(int) nums.size()-i-1]) {
		// 			in_place++;
		// 		}
		// 	}
		// }
		bool skip = false;
		if (n == 1) {
			cout << "0\n";
			continue;
		} else if (n == 2) {
			if (nums[0] == 1) {
				cout << "0\n";
			} else {
				cout << "1\n";
			}
			continue;
		}
	
		long unsigned int i = 0;
		while (i < n && !skip) {
			// loop through both front and back until they cross (the list is sorted)
			// or until they find an unsorted element each.

			if ((int) first == -1) { // haven't found the first unsorted position yet.
				if (i+1 != nums[i]) {
					first = i;  // this index is the first unsorted position
				}	
			} //else {
				// see whether it is in place or not
			//	if (i+1 == nums[i]) {
			//		in_place++;
			//	}
			//}
			if ((int) last == -1) {  // haven't found the last unsorted position yet.
				if (n-i != nums[n-i-1]) {
					last = n-i-1; 
				}
			}// else {
				// see whether it is in place or not
			//	if (nums.size()-i == nums[nums.size()-i-1]) {
			//		in_place++;
			//	}
			//}

			if (i > floor(n/2)) {  // if it gets halfway and nothing crosses, then it's already sorted
				if ((int) first == -1 || (int) last == -1) {
					cout << "0\n";  // it's already sorted
					skip = true;
					break;
				}
			}
			if ((int) first != -1 && (int) last != -1) {
				break;
			}
			i++;
		}

		if (!skip) {
			// now see how many are in place
			for (long unsigned int i=first; i<last+1; i++) {
				if (i+1 == nums[i]) {
					in_place++;
				}
			}
			
			if (in_place > 0) {
				cout << "2\n";
			} else {
				cout << "1\n";
			}				
		}
	}

	return 0;
}
