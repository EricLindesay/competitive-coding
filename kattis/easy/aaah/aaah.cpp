#include <iostream>
#include <cstring>

typedef long long ll;

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    string ret = (s1.length() >= s2.length()) ? "go" : "no";
    cout << ret;
    return 0;
}
