// Time: 15m. OK for the cyrcular solution.
// Return the missing number in an array, considering the range [0, n], where n
//  is the array size.

#include <vector>

using namespace std;

// XOR approach: kind of find-the-unique-value". Bases on the XOR's properties:
// 1. a ^ a = 0;
// 2. a ^ 0 = a;
// 3. order and group don't matter.
class Solution { 
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = n;
        for (int i = 0; i < n; i++)
        {
            missing ^= i;
            missing ^= nums[i];
        }

        return missing;
    }
};

class Solution_v1 { // Still cyclic approach, but more compact.
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (nums[i] != i && nums[i] != n)
            {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
                return i;
        }

        return n;
    }
};

class Solution_v0 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        bool max_found = false;

        for (int i = 0; i < n; )
        {
            if (nums[i] != i)
            {
                if (nums[i] < n)
                {
                    swap(nums[i], nums[nums[i]]);
                }
                else
                {
                    max_found = true;
                    i++;
                }
            }
            else
                i++;
        }

        if (!max_found)
            return n;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
                return i;
        }

        return -1;
    }
};