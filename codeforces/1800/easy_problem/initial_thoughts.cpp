#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

	string s;
	cin >> s;

	vector<int> a(n);
	for (int i=0; i<n; i++) {
		int num;
		cin >> num;
		a[i] = num;
	}

	int ha = 0;
	int aa = 0;
	int ra = 0;
	int da = 0;
	for (int i=0; i<n; i++) {
		cout << s[i];
	}

    return 0;
}
