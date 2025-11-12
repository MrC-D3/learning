// Time 20m. OUT.
// Return the length of the longest polindrome you can build.
// Constraints: letters are case SENSITIVE (so "Aa" is not palindrome).

#include <string>
#include <array>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        constexpr int alphabet_size = 26;

        array<int, alphabet_size*2> frequencies;
        for (auto c : s)
        {
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

class Solution_original
{
public:
    int longestPalindrome(string s) 
    {
        // Constraints say: s consists of lowercase/uppercase letters only.
        //  So, you can use an array that has less overhead than a map.
        array<int, 128> counts{0};

        for (auto c : s)
        {
            counts[c] += 1;
        }

        int longest = 0;
        for (auto count : counts)
        {
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
