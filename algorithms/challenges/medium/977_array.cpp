// Time: 20m for the easy solution (with sorting), so consider +5m for the 
//  medium solution withtou sorting.
// Return an ascending ordered array of the squares of nums[i], that is an  
//  ascending-ordered array of values in [-10^4, 10^4]. Do it in O(n).
// Constraints: nums.size in [1, 10^4].

#include <vector>

using namespace std;


// This solution fills the output from the greatest value.
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

// This solution fills the output from the smallest value.
class Solution_v0 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mid = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mid == -1 && nums[i] >= 0)
            {
                mid = i;
            }

            nums[i] *= nums[i];
        }
        if (mid == -1)
        {
            mid = nums.size();
        }

        int to_fill = 0;
        vector<int> result(nums.size()); // Rember to declar a size!
        int i = 0, j = 1; // Or: right=mid; left=mid-1.
        while (mid + i < nums.size() && mid - j >= 0)
        {
            if (nums[mid+i] < nums[mid-j])
            {
                result[to_fill++] = nums[mid+i];
                i++;
            }
            else
            {
                result[to_fill++] = nums[mid-j];
                j++;
            }
        }
        for ( ; mid + i < nums.size(); i++)
            result[to_fill++] = nums[mid+i];
        for ( ; mid - j >= 0; j++)
            result[to_fill++] = nums[mid-j];

        return result;
    }
};