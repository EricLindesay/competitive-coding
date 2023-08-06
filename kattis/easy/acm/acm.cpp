#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	map<char, int> attempts;  // problem: attempts
	map<char, bool> solved;

	int time;
	char problem;
	string result;
	int problems_solved = 0;
	int total_time = 0;
	while (cin >> time && time != -1) {
		cin >> problem >> result;

		if (attempts.count(problem)) {
			// its already there
			++attempts[problem];
		} else {
			attempts[problem] = 1;
		}

		if (result == "right" && !solved.count(problem)) {
			++problems_solved;
			total_time += time + (attempts[problem] - 1) * 20;
			solved[problem] = true;
		}
	}

	cout << problems_solved << " " << total_time << endl;

    return 0;
}
