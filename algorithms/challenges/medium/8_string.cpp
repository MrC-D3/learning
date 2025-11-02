#include <iostream>
#include <string>
//#include <climits> in case required by INT32_MAX.


using namespace std;


class Solution {
public:
    int myAtoi(string s) 
    {
        // 32 bits, or use long (64bit) to simplify overflow check.
        int to_return{0};

        // Spaces.
        int i = 0;
        for ( ; i < s.size() && s[i] == ' '; i++);
        // If all spaces.
        if (i == s.size())
        {
            return to_return;
        }

        // Sign.
        bool negative{false};
        if (s[i] == '-')
        {
            negative = true;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        // Digits.
        for ( ; i < s.size() && isdigit(s[i]); i++)
        {
            int current = s[i] - '0';

            // Double risk of overflow:
            //  1. when multiplying to_return*10;
            //  2. when adding current.
            if ((to_return <= INT32_MAX/10) && 
              (current <= INT32_MAX - to_return*10))
            {
                to_return = to_return*10 + current;
            }
            else if (!negative)
            {
                to_return = INT32_MAX; // 2147483647
                break;
            }
            else
            {
                to_return = INT32_MIN; // -2147483648
                negative = false;
                break;
            }
        }

        //
        if (negative)
        {
            to_return *= -1;
        }

        return to_return;
    }
};

int main()
{
    return 0;
}