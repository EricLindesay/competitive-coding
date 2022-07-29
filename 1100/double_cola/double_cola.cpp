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
	section = log2((n+5)/5);

	long long power_section = pow(2, section);
	long long remaining = n - 5*(power_section - 1);

	long long index = remaining/power_section;

	cout << names[index] << endl;

    return 0;
}
