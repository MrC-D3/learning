// Time: (estimated) 15m. OK.
// Return true if iterativaly summing the squares of the digits starting from n,
//  you end up to 1.
// Constraints: n in [1, 2^31 - 1].

#include <set>

using namespace std;


// O(K) extra space. If less space, but more cycles, consider Floyd’s algorithm.
class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        
        // K iterations.
        while ((n != 1) && (seen.find(n) == seen.end()))
        {
            seen.insert(n);

            // Compute new n.
            auto old_n = n;
            n = 0;
            while (old_n != 0) // O(logN).
            {
                auto digit = old_n % 10;
                n += digit*digit; // No overflow: int32 has max 10 digits at 9.
                old_n /= 10;
            }
        }

        return n == 1;
    }
};