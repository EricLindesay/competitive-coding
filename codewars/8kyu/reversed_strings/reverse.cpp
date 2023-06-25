#include <string>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

string reverseString (string str) {
    reverse(str.begin(), str.end());
    return (string) str;
}

int main() {
    cout << reverseString("world") << endl;
    return 0;
}

