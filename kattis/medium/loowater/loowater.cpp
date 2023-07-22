#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;

		priority_queue<int, vector<int>, greater<int>> heads;
		priority_queue<int, vector<int>, greater<int>> knights;

		while (n--) {
			int num;
			cin >> num;
			heads.push(num);
		}

		while (m--) {
			int num;
			cin >> num;
			knights.push(num);
		}

		int price = 0;
		bool doomed = false;
		while (!heads.empty()) {
			if (knights.empty()) {
				doomed = true;
				break;
			}
			int head = heads.top();
			heads.pop();

			int knight = knights.top();
			knights.pop();

			if (knight < head) {
				heads.push(head);
				continue;
			}
			price += knight;
		}
		if (doomed) {
			cout << "Loowater is doomed!" << endl;
		} else {
			cout << price << endl;
		}
	}

    return 0;
}
