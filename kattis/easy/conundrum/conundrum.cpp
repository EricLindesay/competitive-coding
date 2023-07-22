#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string per = "PER";
	string word;
	cin >> word;

	int days = 0;
    for (int i = 0; i < word.length(); i++) {
		if (word[i] != per[i%3]) 
			days++;
    }

	printf("%d\n", days);

    return 0;
}
