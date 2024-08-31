#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string dna;
	cin >> dna;

	char current = dna[0];
	int length = 1;
	int maxLength = 1;
	for (int i=1; i<dna.size(); i++) {
		if (dna[i] == current) {
			length += 1;
		} else {
			maxLength = max(length, maxLength);
			current = dna[i];
			length = 1;
		}
	}

	cout << max(length, maxLength);

    return 0;
}
