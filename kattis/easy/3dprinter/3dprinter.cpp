#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	vector<int> days(t+1, -1);
	days[0] = 0;
	days[1] = 1;

	int printers = 1;
	while (printers < days.size() - printers) {
		// what if we just had one printer the entire time
		for (int i=printers; i<days.size() - printers; i++) {
			if (days[i] != -1) {
				if (days[i+printers] == -1)
					days[i+printers] = days[i] + 1;
				else
					days[i+printers] = min(days[i]+1, days[i+printers]);
			}
		}
		printers++;
	}

	/* debug print the vector */
	for (int i=0; i<days.size(); i++) {
		cout << days[i] << " ";
	}
	cout << endl;
	
	cout << days[t] << endl;

    return 0;
}
