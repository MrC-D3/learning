// Time: 15m.
// Return an array[n+1] where array[i] stores the number of 1s in i.
// Constraints: no __builtin_popcount(); n in [0, 10^5].

#include <vector>

using namespace std;

class Solution {
public:
    // Any sequence of n bits is a sequence of n-1 bits left-shifted concatened
    //  with a new lsb equal to 0 (if n is even) or 1 (if n is odd).
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        
        for (int i = 1; i <= n; i++)
        {
            // More efficient than / and %.
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};

class Solution_v0 { // O(NlogN).
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for (int i = 1; i <= n; i++)
        {
            auto log = i;
            while (log > 0)
            {
                ans[i] += log % 2;
                log /= 2;
            }
        }
        
        return ans;
    }
};