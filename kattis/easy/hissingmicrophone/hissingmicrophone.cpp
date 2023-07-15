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
    string word;
    cin >> word;

	int found = word.find("ss");
	if (found != string::npos)
		cout << "hiss";
	else 
		cout << "no hiss";

    return 0;
}
