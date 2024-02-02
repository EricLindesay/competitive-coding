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

class Compare {
	map<string, int> val = {{
		make_pair("upper", 0), 
		make_pair("middle", 1),
		make_pair("lower", 2),
	}};

	public:
		bool operator()(const vector<string> &s1, const vector<string> &s2) {
			int p1 = s1.size() - 1;
			int p2 = s2.size() - 1;
			int val1 = val[s1[p1]];
			int val2 = val[s2[p2]];
			while (p1 >= 0 || p2 >= 0) {
				if (p1 < 0) {
					val1 = val["middle"];
				} else {
					val1 = val[s1[p1]];
				}
				if (p2 < 0) {
					val2 = val["middle"];
				} else {
					val2 = val[s2[p2]];
				}
				if (val1 != val2) {
					return (val1 > val2);
				}
				p1--;
				p2--;
			}
			// They are exactly equal
			return s1[s1.size() - 1].compare(s2[s2.size() - 1]) > 0;
		}
};


vector<string> split(string s, char c) {
	std::stringstream test(s);
	std::string segment;
	std::vector<std::string> seglist;

	while(std::getline(test, segment, c)) {
		seglist.push_back(segment);
	}
	return seglist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;
    cin >> t;

	priority_queue<vector<string>, vector<vector<string>>, Compare> names;
	while (t--) {
		// We don't need to reset the names PQ, this should automatically reset due to popping everything which is pushed
		cin >> n;
		while (n--) {
			string name, classes, c;
			cin >> name >> classes >> c;
			vector<string> s = split(classes, '-');
			s.push_back(name.substr(0, name.size()-1));
			names.push(s);
		}

		while (!names.empty()) {
			cout << names.top()[names.top().size()-1] << '\n';
			names.pop();
		}
		cout << "==============================\n";
	}

    return 0;
}



