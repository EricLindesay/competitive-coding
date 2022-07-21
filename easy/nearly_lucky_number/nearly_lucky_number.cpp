#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	string n;
	cin >> n;

	int count = 0;
	for (char i : n) {
		if (i == '4' || i == '7') count++;
	}
	
	string ans = (count == 4 || count == 7) ? "YES" : "NO"; 
	cout << ans << endl;

    return 0;
}
