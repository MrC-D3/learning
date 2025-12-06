// Time: 15m. Ok for the O(N) space cost solution, OUT for the O(1) cost space.
// Return true if an interger is palindrome in base10.
// Constraints: x in [-2^31, 2^31 - 1].

#include <string>

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

// Without converting in a vector of char/int.
class Solution { 
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        auto tmp = x;
        int magnitude = 1;
        while (tmp > 0)
        {
            tmp /= 10;
            magnitude *= 10;
        }
        magnitude /= 10;
        if (magnitude == 1)
            return true;

        tmp = x;
        int rebuilt = 0;
        int power_10 = 1;
        while (magnitude != 1)
        {
            auto current_digit = tmp % 10;
            rebuilt += ((current_digit * power_10) + (current_digit * magnitude));
            power_10 *= 10;
            magnitude /= 10;
        }

        if (rebuilt != x)
            return false;

        return true;
    }
};

class Solution_v0 {
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