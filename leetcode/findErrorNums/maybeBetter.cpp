#include <iostream>
#include <vector>
#include <numeric>
#include <set>

typedef long long ll;

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
	// This is someone else's solution. I don't think it is more efficient. It uses accumulate
	// twice which is a bit faster than O(n) but i'm not sure its precise efficiency
	// and it also loops through n, so the efficiency is O(n+2a) where a is the efficiency of 
	// the accumulate function.
	
	// However, mine has efficiency of O(2n) in worst case, O(n+2) in best case

    //sum of elements on nums
    int initialSum = accumulate(nums.begin(), nums.end(), 0);

    //put the element of nums into set to remove the duplicate number
    set<int> s;
    for(auto &i: nums){
        s.insert(i);
    }

    //sum of elements of the set
    int sum = accumulate(s.begin(), s.end(), 0);

    //difference of initialSum and sum will give us the repeated number
    int repeatedNum = initialSum - sum;

    //sum of all the natural numbers from 1 to n
    int n = nums.size() + 1;

    //subtracting the sum of elements in set i.e. sum from the sum of the natural numbers will give us the missing number
    int missingNum = n * (n-1)/2 - sum;

    return {repeatedNum, missingNum};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    cout << endl << t << endl;

    return 0;
}
