// Time: 15m.
// Return the indexes of the 2 numbers whose sum is equal to target. Indexes can
//  be returned in any order; solution in O(N).
// Constraints: nums.size() in [2, 10^4]; nums[i] and target in [-10^9, 10^9].

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> to_return{0,1};

        unordered_map<int, int> seen;
        // Since the indexes can be returned in any order, no need of 2 loops,
        //  because if complement is after nums[i], when you read nums[i] you 
        //  just store it in map and when you'll read complement you'll get from
        //  the map. This also makes the map lighter, because the value is an
        //  index not a vector and because you store only data till nums[i] not
        // for the whole nums[] vector.
        for (int i = 0; i < nums.size(); i++)
        {
            auto complement = target - nums[i];
            auto it = seen.find(complement);
            if (it != seen.end())
            {
                return {it->second, i};
            }

            // Here if no pair, store it.
            seen[nums[i]] = i;
        }

        return {};
    }
};

class Solution_v1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> num_index;
        for (int i = 0; i < nums.size(); i++)
        {
            num_index[nums[i]].push_back(i);
        }

        vector<int> to_return{0,1};
        for (int i = 0; i < nums.size(); i++)
        {
            int target_bis = target - nums[i];
            auto it = num_index.find(target_bis);
            if (it != num_index.end())
            {
                if (target_bis == nums[i] && it->second.size() < 2)
                {
                    continue;
                }

                to_return[0] = i;
                to_return[1] = it->second.back();
                break;
            }
        }

        return to_return;
    }
};

int main()
{
    Solution s;
    vector<int> input{2,4,6,2};
    int target = 4;
    auto result = s.twoSum(input, target);
    for (auto i : result)
    {
        cout << i << endl;
    } 

    return 0;
}