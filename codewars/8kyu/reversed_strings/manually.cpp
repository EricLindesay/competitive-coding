#include <string>
#include <iostream>

using namespace std ; 

string reverseString (string str )
{
    char *ans = (char *) malloc(sizeof(str));
    for (int i = 0; i < str.length(); i++) {
        *ans = str[str.length()-1-i];
        ans++;
    }
    ans -= str.length();
    return ans;
}

int main() {
    cout << reverseString("world") << endl;
    return 0;
}

