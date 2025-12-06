// Time: 15m. OUT.
// Return the indexes of the 2 numbers whose sum is equal to target.
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