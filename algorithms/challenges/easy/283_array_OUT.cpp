// Time: 20m. OUT.
// Move all the 0s at the end and keep the existing order; do it in place and 
//  minimize the number of operations.
// Constraints: nums.size in [1, 10^4]; nums[i] in [-2^31, 2^31 - 1].

#include <vector>

using namespace std;

class Solution { // Two pointers, O(N).
public:
    void moveZeroes(vector<int>& nums) {
        int to_fill = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                continue;
            if (to_fill != i)
            {
                nums[to_fill] = nums[i]; // Or just swap.
                nums[i] = 0;
            }
            to_fill++;
        }
    }
};

class Solution_v0 { // O(N^2).
public:
    void moveZeroes(vector<int>& nums) {
        // Bubble sort approach.
        int N = nums.size();
        for (int i = 0; i < N; )
        {
            if (nums[i] != 0)
            {
                i++;
                continue;
            }
            for (int j = i + 1; j < N; j++)
            {
                swap(nums[j-1], nums[j]);
            }
            N--;
        }
    }
};