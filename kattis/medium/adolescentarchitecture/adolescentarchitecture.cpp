#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

double diagonalSize(int l) {
	return sqrt((l*l)/2.0f);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	string type;
	int l;
	priority_queue<int> cubes;
	priority_queue<int> cylinders;

	// A cylinder can be stacked on a cube if the radius is <= the cube length
	// A cube can be stacked on a cylinder if the diagonal size <= radius (sqrt(pow(l, 2)/2))
	while (t--) {
		cin >> type >> l;
		if (type == "cube") {
			cubes.push(l);
		} else {
			cylinders.push(l);
		}
	}

	int prevL = INT_MAX;
	string prev = "cube";
	vector<pair<string, int>> order;  // could reverse all the logic but i'll just reverse the output
	while (!cubes.empty() && !cylinders.empty()) {
		// Take the largest one, compare diagonal lengths
		int cubeDiagonal = diagonalSize(cubes.top());
		if (cubeDiagonal >= cylinders.top()) {
			// Make sure this fits on the previous one
			if (prev == "cube" && cubes.top() > prevL) {
				cout << "impossible";
				return 0;
			} else if (prev == "cylinder" && cubeDiagonal > prevL) {
				cout << "impossible";
				return 0;
			}
			order.push_back(make_pair("cube",cubes.top()));
			prev = "cube";
			prevL = cubes.top();
			cubes.pop();
		} else {
			if (prev == "cube" && cylinders.top() > prevL/2.0f) {
				cout << "impossible";
				return 0;
			} else if (prev == "cylinder" && cylinders.top() > prevL) {
				cout << "impossible";
				return 0;
			}
			// Make sure this fits on the previous one
			order.push_back(make_pair("cylinder",cylinders.top()));
			prev = "cylinder";
			prevL = cylinders.top();
			cylinders.pop();
		}
	}

	while (!cubes.empty()) {
		// If the previous was a cylinder, make sure it fits over the cylinder
		// Otherwise, this should be sorted so cubes can fit over cubes
		if (prev == "cylinder" && diagonalSize(cubes.top()) > prevL) {
			cout << "impossible";
			return 0;
		}
		prev = "cube";
		order.push_back(make_pair("cube", cubes.top()));
		cubes.pop();
	}

	while (!cylinders.empty()) {
		if (prev == "cube" && cylinders.top() > prevL/2.0f) {
			cout << "impossible";
			return 0;
		}
		prev = "cylinder";
		order.push_back(make_pair("cylinder", cylinders.top()));
		cylinders.pop();
	}

	for (int i=order.size()-1; i>=0; i--) {
		cout << order[i].first << " " << order[i].second << '\n';
	}

    return 0;
}
