// Time: 15m.
// Return the only number present once, all the others appear twice.
// Constraints: nums.size in [1, 3*10^4]; nums[i] in [-3*10^4, 3*10^4].

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;

        for (auto n : nums)
        {
            single ^= n;
        }
        // Or with accomulate(), but C++20.

        return single;
    }
};