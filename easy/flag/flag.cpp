#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;

	int current_colour = -1;
	for (int i=0; i<n; i++) {
		string row;
		cin >> row;
		for (int j=0; j<m; j++) {
			if (i == 0 && j == 0) {
				current_colour = row[j];
				continue;
			}
			if (j == 0 && current_colour != -1) {  // check row's arent same colour
				if (row[j] == current_colour) {
					cout << "NO";
					return 0;
				}
				current_colour = row[j];
			} else {
				if (row[j] != current_colour) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";
    return 0;
}
