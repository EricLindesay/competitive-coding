#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	return a.second > b.second;
}

vector<string> topKFrequent(vector<string>& words, int k) {
	map<string, int> wf;  // a map containing the frequencies of the words
	for (int i=0; i<words.size(); i++) {
		if (wf.count(words[i])) {
			++wf[words[i]];
		} else {
			wf[words[i]] = 1;
		}
	}

	vector<vector<string>> sortedWords(500);
	for (auto it: wf) {
		sortedWords[it.second].push_back(it.first);
	}

	vector<string> ans;
	for (int i=sortedWords.size()-1; i>=0; i--) {
		if (sortedWords[i].size() <= 0) continue;
		sort(sortedWords[i].begin(), sortedWords[i].end()); // sort the words in each category lexographically
		for (int j=0; j<sortedWords[i].size(); j++) {
			if (k-- > 0)
				ans.push_back(sortedWords[i][j]);
			else
				return ans;
		}
		if (sortedWords[i].size() > 0) cout << endl;
	}

	return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
	int k = 2;
	vector<string> ret = topKFrequent(words, k);
	for (int i=0; i<k; i++) {
		cout << ret[i] << " ";
	}
	cout << endl << endl;

	words = {"glarko","zlfiwwb","nsfspyox","pwqvwmlgri","qggx","qrkgmliewc","zskaqzwo","zskaqzwo","ijy","htpvnmozay","jqrlad","ccjel","qrkgmliewc","qkjzgws","fqizrrnmif","jqrlad","nbuorw","qrkgmliewc","htpvnmozay","nftk","glarko","hdemkfr","axyak","hdemkfr","nsfspyox","nsfspyox","qrkgmliewc","nftk","nftk","ccjel","qrkgmliewc","ocgjsu","ijy","glarko","nbuorw","nsfspyox","qkjzgws","qkjzgws","fqizrrnmif","pwqvwmlgri","nftk","qrkgmliewc","jqrlad","nftk","zskaqzwo","glarko","nsfspyox","zlfiwwb","hwlvqgkdbo","htpvnmozay","nsfspyox","zskaqzwo","htpvnmozay","zskaqzwo","nbuorw","qkjzgws","zlfiwwb","pwqvwmlgri","zskaqzwo","qengse","glarko","qkjzgws","pwqvwmlgri","fqizrrnmif","nbuorw","nftk","ijy","hdemkfr","nftk","qkjzgws","jqrlad","nftk","ccjel","qggx","ijy","qengse","nftk","htpvnmozay","qengse","eonrg","qengse","fqizrrnmif","hwlvqgkdbo","qengse","qengse","qggx","qkjzgws","qggx","pwqvwmlgri","htpvnmozay","qrkgmliewc","qengse","fqizrrnmif","qkjzgws","qengse","nftk","htpvnmozay","qggx","zlfiwwb","bwp","ocgjsu","qrkgmliewc","ccjel","hdemkfr","nsfspyox","hdemkfr","qggx","zlfiwwb","nsfspyox","ijy","qkjzgws","fqizrrnmif","qkjzgws","qrkgmliewc","glarko","hdemkfr","pwqvwmlgri"};
	k = 14;
	ret = topKFrequent(words, k);
	for (int i=0; i<k; i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
    return 0;
}
