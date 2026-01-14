// The easy solution requires 15m, so condider +5m for the medium solution, i.e. 
//  without using a string, so with O(1) space. OUT.

#include <climits> // For constants like INT_MAX.

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Reverse never negative, but -9/10=0, so it would be considered true.
        if (x < 0)
            return false;
        if (x / 10 == 0)
            return true;
        // Not palindrome if end with 0, because 0 can't be at the beginning.
        if (x % 10 == 0) 
            return false;
        
        int reverse = 0;
        while (reverse < x)
        {
            reverse = (reverse*10) + (x%10);
            x /= 10;
        }

        return (reverse == x) || ((reverse/10) == x);
    }
};

// Without converting in an vector/string.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int original = x;
        int reverted = 0;
        while (original != 0 && reverted < (INT_MAX/10-10))
        {
            int unit = original % 10;
            original /= 10;

            reverted *= 10;
            reverted += unit;
        }

        return x == reverted;
    }
};