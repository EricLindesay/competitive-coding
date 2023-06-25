#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector<string> subsequences(vector<string>& arr) {
	vector<string> ans = {""};
	for (string a : arr) {
		ans.push_back(a);
	}

	// now need to do next permutation but only on some of the array
}

int maxLength(vector<string>& arr) {
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<string> arr = {"un", "iq", "ue"};
	cout << maxLength(arr) << endl;
    return 0;
}
