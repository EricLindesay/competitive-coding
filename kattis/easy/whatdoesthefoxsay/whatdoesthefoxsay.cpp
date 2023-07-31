#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	cin.ignore(256, '\n');  // required so that cin gets the correct line for the first line

	while (t--) {
		map<string, bool> knownNoises;
		// get the first line
		string noises;
		getline(cin, noises);		

		// get the known noises
		string line;
		getline(cin, line);
		while (line != "what does the fox say?") {
			// split the line to get the noise
			stringstream ss(line);
			string knownNoise;
			ss >> knownNoise >> knownNoise >> knownNoise; // the noise is the third word
			knownNoises[knownNoise] = true;
			getline(cin, line);
		}

		// go through each word in the input, see if the noise is already known. If it isn't then print it
		stringstream noisess(noises);
		string noise;
		while (noisess >> noise) {
			if (!knownNoises.count(noise)) {  // its not known so print it
				cout << noise << " ";
			}
		}
		cout << endl;
	}

    return 0;
}
