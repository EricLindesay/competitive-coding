#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<string> words;
	set<string> compoundWords;

	string input;
	while (cin >> input) {
		words.push_back(input);
	}

	for (int i=0; i<words.size(); i++) {
		for (int j=0; j<words.size(); j++) {
			if (i == j) continue;
			compoundWords.emplace(words[i]+words[j]);
		}
	}

	for (string word : compoundWords) {
		cout << word << endl;
	}

    return 0;
}
