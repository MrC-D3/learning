// Time: 15m. Ok.
// Return true if there is at least a duplicate.
// Constraints: nums.size in [1, 10^5], values in [-10^9, 10^9].

#include <vector>
#include <unordered_set>

using namespace std;

// Exploiting the return value of unordered_set<>.insert().
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        seen.reserve(nums.size()); // To avoid rehashing.

        for (auto n : nums)
        {
            auto [_, inserted] = seen.insert(n);
            if (!inserted)
                return true;
        }

        return false;
    }
};

class Solution_v0 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto n : nums)
        {
            if (seen.find(n) == seen.end())
                seen.insert(n);
            else
                return true;
        }

        return false;
    }
};