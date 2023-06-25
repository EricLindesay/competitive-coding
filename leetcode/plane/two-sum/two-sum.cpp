#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> targets;
        // target number + the index of the value which got that

        for (int i = 0; i < nums.size(); i++)
        {
            auto find = targets.find(nums[i]);
            if (find != targets.end()) // if the num is in targets
            {                          // return that ones position and the current ones position
                return {find->second, i};
            }
            else
            { // the number isn't in the map, so add it
                targets[target - nums[i]] = i;
            }
        }
        return {};
    };
};

int main()
{
    vector<int> vect{3, 3};
    int target = 6;
    vector<int> vectOut = Solution().twoSum(vect, target);

    printf("%d %d\n", vectOut[0], vectOut[1]);
}