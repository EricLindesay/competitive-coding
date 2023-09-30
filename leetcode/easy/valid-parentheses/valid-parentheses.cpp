#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
		string::iterator it = s.begin();
		for (it; it != s.end(); it++) {
			// if you see an open parenthesis
			if (*it == '(' || *it == '[' || *it == '{') {
				// add it to the stack
				paren.push(*it);
			} else {
				// otherwise, its a closing
				// we need to pop from the stack and make sure it is the proper closing partner
				if (paren.empty())  // if there is nothing in the stack then its not valid
					return false;
				char partner = paren.top();
				paren.pop();
				if (*it == ')' && partner != '(')
					return false;
				else if (*it == ']' && partner != '[')
					return false;
				else if (*it == '}' && partner != '{')
					return false;
			}
		}
		return paren.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().isValid("()") << endl;
	cout << Solution().isValid("()[]{}") << endl;
	cout << Solution().isValid("(]") << endl;
	cout << Solution().isValid("]") << endl;

    return 0;
}
