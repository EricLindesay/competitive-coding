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

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	vector<vector<int>> contestants;
	priority_queue<vector<int>, vector<int>, compare> pq;

	while (n--) {
		int s, p, f, o;
		cin >> s >> p >> f >> o;
		contestants.push_back({s, p, f, o});
		pq.push_back({s, p, f, o});
	}

    return 0;
}
