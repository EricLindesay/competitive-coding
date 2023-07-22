#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
    cin >> n >> m;

	int bestCandidate = -1;
	int bestScore = -1;
	int candidate = 1;
	while (n--) {
		int candidateScore = 0;
		// Find the score of the candidate
		for (int i=1; i<m+1; i++) {
			string userResult;
			string expectedOutput;
			cin >> userResult;
			if (i%3 == 0 && i%5 == 0)
				expectedOutput = "fizzbuzz";
			else if (i%3 == 0)
				expectedOutput = "fizz";
			else if (i%5 == 0)
				expectedOutput = "buzz";
			else 
				expectedOutput = to_string(i);

			if (userResult == expectedOutput)
				candidateScore++;
		}
		// if its the best score, update
		if (candidateScore > bestScore) {
			bestCandidate = candidate;
			bestScore = candidateScore;
		}
		candidate++;
	}

	cout << bestCandidate << endl;

    return 0;
}
