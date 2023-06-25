#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

void print_subset(vector<int> &nums, int lower_bound, int upper_bound)
{ // inclusive
    printf("%d %d - ", lower_bound, upper_bound);
    for (int i = lower_bound; i < upper_bound + 1; i++)
    {
        printf("%d", nums[i]);
    }
    printf("\n");
}

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int lower = 0;
        int upper = 0;
        int longest_substring = 0;
        queue<int> zeroPos;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]) // if its a 1, just accept it
            {
                upper++;
            }
            else
            {
                if (zeroPos.size() < k)
                {
                    // You've found a zero and you still have flips left, accept it
                    upper++;
                    zeroPos.push(i);
                }
                else
                {
                    if (zeroPos.size() == 0)
                    {
                        printf("in here\n");
                        upper++;
                        lower = upper;
                        if (k > 0)
                            zeroPos.push(i);
                    }
                    else
                    {
                        // You've found a zero but you've run out of flips
                        // Set the substring length
                        // longest_substring = max(longest_substring, i - lower);
                        upper++;

                        // set lower to be the lowest zero
                        lower = zeroPos.front() + 1;
                        zeroPos.pop();

                        // add the new zero position in
                        zeroPos.push(i);
                    }
                }
            }

            if (i != nums.size() - 1)
                print_subset(nums, lower, upper);
            longest_substring = max(longest_substring, upper - lower + 1);
        }
        return longest_substring;
    }
};

int main()
{
    // https://leetcode.com/problems/max-consecutive-ones-iii/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Find the largest number of consecutive 1s with at most k 0s
    vector<int> vect = {0, 0, 1, 1, 1, 0, 0};
    printf("%d\n", Solution().longestOnes(vect, 0));
    return 0;
}
