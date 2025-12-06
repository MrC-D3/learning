// Time: 15m. OUT.
// Return the index if target is in nums (an ascending-ordered unique-values 
//  array) or -1 otherwise. Do it in O(lgN).
// Constraints: nums.size in [1, 10^4]; nums[i] and target in [-10^4, 10^4].

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        // Usually not -1, so condition "start<end" and update "end=mid;".
        int end = nums.size() - 1;
        while (start <= end)
        {
            auto mid = start + (end-start) / 2; // (end-start)/2 is an offset.
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                // Search on middle+1 and end.
                start = mid + 1;
            }
            else
            {
                // Search on start and middle-1;
                end = mid - 1;
            }
        }

        return -1;
    }
};