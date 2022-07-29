#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
	n--;
	string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

	long long section;
	section = (-2.5 + sqrt(2.5*2.5 + 4*2.5*n)) / 5;
	cout << section << endl;

	long long remaining = n - 2.5 * section * (section+1);
	cout << remaining << endl;

	cout << names[remaining/(section+1)] << endl;

    return 0;
}
