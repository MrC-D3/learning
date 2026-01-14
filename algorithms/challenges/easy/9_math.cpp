// Time: 15m.
// Return true if an interger is palindrome in base10.
// Constraints: x in [-2^31, 2^31 - 1].
// Note: this problem can be solved with O(1) but with a medium solution.

#include <string>

using namespace std;

// Basic solution: convert the integer in a string.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        string x_str;
        while (x > 0)
        {
            x_str.push_back( '0' + (x%10));
            x /= 10;
        }

        auto len = x_str.size();
        for (int i = 0; i < len/2; i++)
        {
            if (x_str[i] != x_str[len-1-i])
                return false;
        }

        return true;
    }
};