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

	int smallestNeeded = pow(2, n-1);
	int pages = 0;  // total number of pages, in units of smallest page
	double tape = 0;
	double rt2 = sqrt(2);

	double tapeSize = pow(2, -3.0/4.0);
	for (int i=1; i<n; i++) {
		int num;
		cin >> num;
		int pageSize = 1 << (n-i-1);
		pages += pageSize * num;

		if (pages < smallestNeeded) {
			int thisAmount = (smallestNeeded - pages)/pageSize;
			// You will eventually need {thisAmount} pages of this size
			// Which means you need to merge the next smallest one down this many times
			tape += tapeSize / pow(rt2, i) * thisAmount;
		} else {  // you already have enough pages so just stop accepting input
			break;
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
