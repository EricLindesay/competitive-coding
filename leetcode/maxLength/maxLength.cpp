#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;


bool common_char(string s1, string s2) {
	// both strings are sorted
	int i1=0, i2=0;
	int l1 = s1.length(), l2 = s2.length();
	while (i1 < l1 && i2 < l2) {
		if (s1[i1] == s2[i2]) return true;
		
		if (s1[i1] > s2[i2]) {
			++i2;
		} else {
			++i1;
		}
	}
	return false;
}

class Node {
	public:
		string word;
};

class Graph {
	public:
		vector<Node*> nodes;
		vector<pair<Node*, Node*>> edges;

		// use clique problem
		void addNode(Node *new_node) {
			for (Node* node : nodes) {
				// see if they have a common character, if they don't add the edge
				// between them
				if (!common_char(node->word, new_node->word)) {
					edges.push_back({node, new_node});
				}
				nodes.push_back(new_node);
			}
		}
};

int maxLength(vector<string>& arr) {
    // create a graph.
	// Similar problem to Stand-Up Math's 5 word 5 letter problem
	
	// sort each string before you put it in the graph. This overall should save execution time
	if (common_char("abcdefg", "hijklmnopqrstuvwxyz")) cout << "Common char" << endl;
	else cout << "No common" << endl;
}

vector<Node *> bronKerbosh1(vector<Node *> R, vector<Node *> P, vector<Node *> X) {
	if (P.size() == 0 && X.size() == 0) {
		return;
	}
	for (Node *n : P) {
		R.push_back(n);
		bronKerbosh1(R, )
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<string> arr = {"un", "iq", "ue"};
	cout << maxLength(arr) << endl;

    return 0;
}
