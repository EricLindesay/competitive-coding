#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	vector<int> sizes(n-1, 0);

	int smallestNeeded = pow(2, n-1);

	int pages = 0;  // total number of pages, in units of smallest page
	int index = 1;
	double tape = 0;
	double rt2 = sqrt(2);

	double tapeSize = pow(2, -3.0/4.0);
	for (int &num : sizes) {
		cin >> num;
		int pageSize = pow(2, n-index-1);
		pages += pageSize * num;
		index++;

		if (pages < smallestNeeded) {
			int thisAmount = (smallestNeeded - pages)/pageSize;
			// You will eventually need {thisAmount} pages of this size
			// Which means you need to merge the next smallest one down this many times
			tape += tapeSize / pow(rt2, index-1) * thisAmount;
		}
	}
	if (pages < smallestNeeded) {
		cout << "impossible" << endl;
		return 0;
	}

	// do the A2 -> A1 merge
	tape += tapeSize; 
	printf("%.10lf\n", tape);

	return 0;
}
