// Time: 20m. OK.
// Return how many ways to reach step_n if only jumps of 1 or of 2.
// Constraints: n in [1,45].

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int step_before2 = 1;
        int step_before1 = 1;

        for (int i = 2; i <= n; i++)
        {
            auto current = step_before2 + step_before1;

            step_before2 = step_before1;
            step_before1 = current;
        }

        return step_before1;
    }
};