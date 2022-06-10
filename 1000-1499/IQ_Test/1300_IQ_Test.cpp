#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string s, string delim);


int read_n() {
    int n;
    string s;
    getline(cin, s);

    sscanf(s.c_str(), "%d", &n);
    return n;
}

vector<int> read_nums(int n) {
    vector<int> nums;
    string s;
    getline(cin, s);
    vector<string> tokens = split(s, " ");
    for (string token : tokens) {
        nums.push_back(stoi(token));
    }
    return nums;
}

vector<string> split(string s, string delim) {
    size_t pos = 0;
    string token;
    vector<string> tokens;
    while ((pos = s.find(delim)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delim.length());
    }
    tokens.push_back(s);  // add what is left of s
    return tokens;
}

int main() {
    int n = read_n();
    vector<int> arr = read_nums(n);

    // find the (index+1) of the number which num%2 is not the same as the others.
    vector<vector<int>> modulos;
    vector<int> test = {};
    modulos.push_back(test);
    modulos.push_back(test);

    // find which are even and odd
    for (int i=0; i<arr.size(); i++) {
        if (modulos[(arr[i]+1)%2].size() >= 2) {
            // if the other one has 2 or more values, this is the odd one out.
            printf("%d", (i+1));
            return 0;
        }
        // add the index
        modulos[arr[i]%2].push_back(i+1);
    }

    // there will only be one odd one out, so we know it will be the first
    if (modulos[0].size() > modulos[1].size()) {  // even > odd
        printf("%d", modulos[1][0]);
    } else {
        printf("%d", modulos[0][0]);  // odd > even
    }

    return 0;
}

