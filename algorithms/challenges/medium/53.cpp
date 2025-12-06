// Time: 
// Given an integer array nums, find the subarray with the largest sum, and 
//  return its sum. 
// Example 1: Input: nums = [-2,1,-3,4,-1,2,1,-5,4] Output: 6
//  Explanation: The subarray [4,-1,2,1] has the largest sum 6.

#include <vector>
#include <algorithm>


using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] = std::max(nums[i], nums[i]+nums[i-1]);
            result = std::max(result, nums[i]);
        }

        return result;
    }
};