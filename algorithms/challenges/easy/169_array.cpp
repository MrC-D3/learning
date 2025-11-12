// Time: 20m.
// Return the Majority element, i.e. the element presents more than N/2 times.
// Constraints: the Majority element is always present, the values are in 
//  [-10^9, 10^9], N in [1, 5*10^4].

#include <vector>
#include <unordered_map>

using namespace std;

// Boyer–Moore Voting Algorithm.
// This works because while any non-majority elements will reach count==0 and 
//  won't be the candidate anymore, only the majority element may reach 
//  intermediate steps where count reaches 0, but then it will become again the
//  candidate eventually and keep it till the end of the loop.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (auto n : nums)
        {
            if (count == 0)
            {
                candidate = n;
            }

            count += (n == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

class Solution_v0 {
public:
    int majorityElement(vector<int>& nums) {
        int frequency_goal = nums.size() / 2 + 1;
        unordered_map<int, int> frequencies;

        for (auto n : nums)
        {
            frequencies[n] += 1;
        }

        for (auto [n, f] : frequencies)
        {
            if (f >= frequency_goal)
            {
                return n;
            }
        }

        return 0;
    }
};