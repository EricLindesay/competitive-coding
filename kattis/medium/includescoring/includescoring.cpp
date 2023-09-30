#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int compare(vector<int> &a, vector<int> &b) {
	return 0;
}

class Compare {
public:
    bool operator()(vector<int> a, vector<int> b) {
        if (a[0] < b[0]) {
            return true;
		} 
		if (a[0] == b[0] && a[1] > b[1]) {
			return true;
		} 
		if (a[0] == b[0] && a[1] == b[1] && a[2] > b[2]) {
			return true;
		}

        return false;
    }
};

int main() {
	vector<int> scores = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	vector<int> contestants(n);
	priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

	for (int i=0; i<n; i++) {
		int s, p, f, o;
		cin >> s >> p >> f >> o;
		pq.push({s, p, f, o, i});
	}
	
	int i = 0;
	while (!pq.empty()) {
		vector<int> top = pq.top();
		pq.pop();
		vector<vector<int>> tied = {top};
		while (!pq.empty()) {
			// Check if this is the same. If it isn't the same then break.
			// Otherwise pop and keep track of that contestant
			if (pq.top()[0] == top[0] && pq.top()[1] == top[1] && pq.top()[2] == top[2]) {
				cout << pq.top()[4] << " is the best" << endl;
				// they are tied
				tied.push_back(pq.top());
				pq.pop();
			} else {
				break;
			}
		}

		int tiedSum = 0;
		for (int j=0; j<tied.size(); j++) {
			if (i >= 30) {
				break;
			}

			tiedSum += scores[i];
			i++;
		}
		int average = ceil((double) tiedSum / (double) tied.size());

		for (int j=0; j<tied.size(); j++) {
			contestants[tied[j][4]] = average + tied[j][3];
		}
	}

	for (int i=0; i<contestants.size(); i++) {
		cout << contestants[i] << endl;
	}

    return 0;
}
