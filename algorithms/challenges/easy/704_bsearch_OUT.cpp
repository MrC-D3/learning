// Time O(15m). OUT OF TIME.
// Given an array of integers nums which is sorted in ascending order, and an 
// integer target, write a function to search target in nums. If target exists, 
// then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.
// Example: Input [-1,0,3,5,9,12], target = 9.
// Example: Input [-1], target = 2.
// 1 <= nums.length <= 10^4.
// All the integers in nums are unique.

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