// Time: 20m. OUT.
// Return an ascending ordered array of the squares of nums[i], an ascending 
//  ordered array. Do it in O(n).
// Constraints: nums.size in [1, 10^4]; nums[i] in [-10^4, 10^4].

#include <vector>
#include <cmath>

using namespace std;

// Solution that exploits the symmetry around 0.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size()); // All values at 0 by default.

        int i = 0;
        int j = nums.size() - 1;
        int h = j;
        while (i <= j)
        {
            if (abs(nums[i]) > abs(nums[j]))
            {
                result[h--] = nums[i] * nums[i];
                i++;
            }
            else
            {
                result[h--] = nums[j] * nums[j];
                j--;
            }
        }

        return result;
    }
};