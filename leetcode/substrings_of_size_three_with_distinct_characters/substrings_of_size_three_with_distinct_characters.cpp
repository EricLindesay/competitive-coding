#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        if (s.length() < 3)
            return 0;

        int count = 0;
        for (int i = 0; i < s.length() - 2; i++)
        {
            if (s[i] == s[i + 1])
                continue;
            if (s[i + 1] == s[i + 2])
                continue;
            if (s[i] == s[i + 2])
                continue;
            count++;
        }
        return count;
    }
};

int main()
{
    // https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/submissions/977150500/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    printf("%d\n", Solution().countGoodSubstrings("a"));

    return 0;
}
