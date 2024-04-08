#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	map<string, vector<string>> genuses;
	map<string, vector<string>> specieses;
	string genus, species;
	// max number of repeats
	
	map<string, int> repeats;

	while (t--) {
		cin >> genus >> species;
		genuses[genus].push_back(species);
		//specieses[species].push_back(genus);
		if (repeats.count(genus+" "+species)) {
			repeats[genus+" "+species]++;
		} else {
			repeats[genus+" "+species] = 1;
		}
	}
		// Two of the same species are bad
		// Same genus are all fine
		// Different genus are bad
		
		int pots = 0;
		// How many duplicate species are there in each genus?
		// Number of pots = number of genus + number of duplicates in each genus
		// If there are two different duplicates, thats one pot
		// If there are two of the same species, thats two pots
		for (pair<string, vector<string>> genusMap : genuses) {
			int max_dupes = 1;
			for (string s : genusMap.second) {
				max_dupes = max(max_dupes, repeats[genusMap.first+" "+s]);
			}
			pots += max_dupes;
		}
		cout << pots << endl;

    return 0;
}
