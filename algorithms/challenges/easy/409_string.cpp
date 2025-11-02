// What was the goal?

#include <string>
#include <unordered_map>


using namespace std;

class Solution
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

class Solution_v0
{
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> counts;

        for (auto c : s)
        {
            counts[c] += 1;
        }

        int longest = 0;
        for (auto [key, value] : counts)
        {
            if (value % 2 == 0)
            {
                longest += value;
            }
            else
            {
                longest += value - 1;
            }
        }

        if (longest < s.size())
        {
            longest += 1;
        }

        return longest;
    }
};