#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        map<string, int> m;
        for (int i = 0; i < s.length() - 10; i++)
        {
        }
    }
};

int main()
{
    // https://leetcode.com/problems/repeated-dna-sequences/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto t = Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (int i = 0; i < t.size(); i++)
        printf("%s\n", t[i]);

    return 0;
}
