#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	map<string, int> variables;
	map<int, string> values;
	
	string cmd;
	while (cin >> cmd) {
		if (cmd == "def") {
			string variableName;
			int variableValue;
			cin >> variableName >> variableValue;

			if (variables.count(variableName)) {  // if variable is already defined
				// remove the old value for the variable in the value: variable map
				values.erase(variables[variableName]);
			}
			variables[variableName] = variableValue;
			values[variableValue] = variableName;
		} else if (cmd == "calc") {
			int calculation = 0;
			bool unknown = false;
			string op = "+";
			string var;
			// parse the calculation
			while (op != "=") {
				cin >> var;
				cout << var << " ";
				// read the variable value and apply the operator
				// if the variable exists
				if (variables.count(var)) {
					if (op == "+")
						calculation += variables[var];
					else if (op == "-")
						calculation -= variables[var];
				} else {
					unknown = true;
				}
				cin >> op;
				cout << op << " ";
			}
			if (values.count(calculation) && !unknown) {
				// From the result of the calculation, try and find the variable which corresponds to that value, if you find it then print the value, otherwise print "unknown"
				cout << values[calculation] << endl;
			} else {
				// If there were any unknowns, print unknown
				cout << "unknown" << endl;
			}

		} else if (cmd == "clear") {
			variables.clear();
			values.clear();
		}
	}

    return 0;
}
