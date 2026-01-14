// Time: 15m.
// Return the index if target is in nums (an ascending-ordered unique-values 
//  array) or -1 otherwise. Do it in O(logN).
// Constraints: nums.size in [1, 10^4]; nums[i] and target in [-10^4, 10^4].

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        while(end > start) // end >= start if end = nums.size()-1.
        {
            int mid = start + (end-start)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        return -1;
    }
};