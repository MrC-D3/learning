// Time 20m.
// Return the length of the longest polindrome you can build.
// Constraints: letters are case SENSITIVE (so "Aa" is not palindrome).

#include <string>
#include <array>

using namespace std;


class Solution
{
public:
    int longestPalindrome(string s) 
    {
        // It's a string, so the key of the map can only be in the range of the
        //  ASCII value and arrays are faster than maps.
        array<int, 128> counts{0};

        for (auto c : s)
        {
            counts[c] += 1;
        }

        int longest = 0;
        for (auto count : counts)
        {
            // Doing (count&1)==0 is faster. Don't forget the parenthesis since
            //  operator== has higher priority than operator&.
            if (count % 2 == 0)
            {
                longest += count;
            }
            else
            {
                longest += count - 1;
            }
        }

        if (longest < s.size())
        {
            longest += 1;
        }

        return longest;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        constexpr int alphabet_size = 26;

        array<int, alphabet_size*2> frequencies;
        for (auto c : s)
        {
            // Use islower() to distinguish between lower and upper letters.
            if (c >= 'A' && c <= 'Z')
            {
                frequencies[alphabet_size + c - 'A'] += 1;
                continue;
            }
            
            frequencies[c - 'a'] += 1;
        }

        int result = 0;
        int odd = 0;
        for (int i = 0; i < alphabet_size*2; i++)
        {
            if (frequencies[i] % 2 == 0)
            {
                result += frequencies[i];
            }
            else
            {
                odd = 1;
                result += frequencies[i] - 1;
            }
        }

        // Or just add 1 if result < s.size().
        return result + odd;
    }
};