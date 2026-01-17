// Time: (estimated) 15m. OK.
// In digits[] a base10 number with most significant digit in digits[0]. Return
//  the result of summing 1.
// Constraints: digits.size in [1, 100].

#include <vector>
#include <algorithm>

using namespace std;

// O(N) extra space. True there isn't push_front(), but there's insert().
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        // Modify the input, but return another vector: bad code smell.
        //  Just init carry at 1 and store the sum in a variable local in the
        //  loop.
        digits.back() += 1;
        int carry = 0;
        for (auto it = digits.rbegin(); it != digits.rend(); it++)
        {
            *it += carry;
            carry = *it / 10;
            result.push_back(*it % 10);
        }

        if (carry > 0)
            result.push_back(carry);

        reverse(result.begin(), result.end());
        return result;
    }
};