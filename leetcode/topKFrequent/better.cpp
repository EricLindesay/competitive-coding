#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
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

	vector<pair<int, string>> pq;
	for (auto &it: wf) {
		pq.push_back({it.second, it.first});
	}

	sort(pq.begin(), pq.end(), cmp);
	vector<string> ans;
	for (int i=0; i<k; i++) {
		ans.push_back(pq[i].second);
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
