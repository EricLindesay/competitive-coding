#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <list>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string input;
	cin >> input;

	list<char> output;
	output.push_back(input[0]);
	
	list<char>::iterator cursor = output.begin();

	int strLen = input.length();
	for (int i=1; i<strLen; i++) {
		if (input[i] == 'L') 
			cursor--;
		else if (input[i] == 'R')
			cursor++;
		else if (input[i] == 'B') {
			list<char>::iterator copy = cursor;
			cursor--;
			output.erase(copy);
			// probably could have also done output.erase(cursor++) instead of having to copy but oh well
		}
		else {
			cursor++; 
			output.insert(cursor, input[i]);  // this adds the element directly before the current, so increment and drecement the pointer before and after
			cursor--;
		}
	}

	// print the list
	for (auto it=output.begin(); it != output.end(); it++) {
		cout << *it;
	}
	cout << endl;

    return 0;
}
