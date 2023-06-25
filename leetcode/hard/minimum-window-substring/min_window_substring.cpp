#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>

typedef long long ll;

using namespace std;

string minWindow(string s, string t) {
	// go along until you see a character which is in t
	// store that index
	// Then go along, until you have seen all characters in t
	unordered_map<char, int> ft; // stores the frequencies of each character in t
								 // If the int is zero, then you know that you have previously seen the char.
	unordered_map<char, vector<int>> fs; // stores the index of each character we care about in s. Since it can repeat, we have to have a vector
	for (char c: t) {
		if (ft.find(c) != ft.end())	++ft[c];
		else ft.insert(make_pair(c, 1));		
	}

	int indices[100000];
	memset(indices, -1, sizeof(indices));

	int max_index = INT32_MAX-2;
	int min_index = -1;
	int remaining_chars = t.length();
	int prev_min = -1, prev_max = INT32_MAX-2;
	for (int i=0; i<s.length(); i++) {
		char c = s[i];
		auto found = ft.find(c);
//		printf("s[%d] = %c\n", i, c);
		if (found != ft.end()) {
			// after you add a character, see whether you have seen all of them		
			if (remaining_chars != 0) {
				// see if you can find the character.
				// If you can find the character and this one is a repeat
				// then you should overwrite since you haven't seen all the characters yet.
				// in the else statement, its a bit different
				if (found->second > 0) { // we still want to add this character's index
					if (fs.find(c) != fs.end())	{
						fs[c].push_back(i); 
						indices[i] = 1;
					}
					else {
						if (remaining_chars == t.length()) {
							prev_min = i; // for first found, set prev_min to there
						}
						fs.insert(make_pair(c, vector<int>{i})); 
						indices[i] = 1;
					}
					--ft[c]; // we have now seen that character once more
					--remaining_chars;
					prev_max = i;
					if (remaining_chars == 0) {
						if (prev_max-prev_min < max_index-min_index) {
							max_index = prev_max;
							min_index = prev_min;
						}
					}
				} else { // we have found all the repeats we need for this character
					indices[i] = 1;
					if (fs[c][0] == prev_min) while (indices[++prev_min] <= 0);
					indices[fs[c][0]] = -1;
					fs[c].erase(fs[c].begin());
					fs[c].push_back(i);
				}
			} else {
				prev_max = i;
				indices[i] = 1;
				indices[fs[c][0]] = -1;
				int deleting = fs[c][0];
				fs[c].erase(fs[c].begin());
				fs[c].push_back(i);

				if (deleting == prev_min) { // if you were removing the previous minimum
					while (indices[++prev_min] <= 0);  // find the next min
				}

				if (prev_max-prev_min < max_index-min_index) {
					max_index = prev_max;
					min_index = prev_min;
				}
			}
		}
	}
	if (remaining_chars > 0) {
		return "";
	}

	string ans;
	for (int i=min_index; i<=max_index; i++) {
		ans.push_back(s[i]);
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout << s << "-" << t << endl << "\"" << minWindow(s, t) << "\"" << endl << endl;
	s = "A";
	t = "A";
	cout << s << "-" << t << endl << "\"" << minWindow(s, t) << "\"" << endl << endl;
	s = "A";
	t = "AA";
	cout << s << "-" << t << endl << "\"" << minWindow(s, t) << "\"" << endl << endl;
	s = "ab";
	t = "a";
	cout << s << "-" << t << endl << "\"" << minWindow(s, t) << "\"" << endl << endl;
	s = "bba";
	t = "ab";
	cout << s << "-" << t << endl << "\"" << minWindow(s, t) << "\"" << endl << endl;
	s = "baa";
	t = "ab";
	cout << s << "-" << t << endl << "\"" << minWindow(s, t) << "\"" << endl << endl;
    return 0;
}
