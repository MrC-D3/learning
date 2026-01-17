// Time: (estimated) 15m. OK.
// In cost[i] you have the cost to move from step i by 1 or 2. Return the 
//  smallest cost to reach the end of the steps.
// Constraints: cost.size in [2, 1000]; cost[i] in [0, 999].

#include <vector>

using namespace std;


// O(N) extra space.
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto cost_size = cost.size();
        vector<int> dp(cost_size + 1, 0); // Or store just prev1 and prev2.

        // Add the cost to reach [i] to its cost to move from [i].
        for (int i = 2; i < cost_size + 1; i++) // Or just <= cost_size.
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);

        return dp.back();
    }
};