// Time 15m. OK.
// Given two strings s and t, return true if t is an anagram of s, and false 
// otherwise.
// Example: Input s = "anagram", t = "nagaram"; Output true.
// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

#include <string>
#include <unordered_map>
#include <array>

using namespace std;

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if (s.size() != t.size())
        {
            return false;
        }

        // Constraints say: s and t consist of lowercase English letters.
        //  So, fixed number of keys: no need of an hash map, an array is fine.
        //  Fixed number of keys also means: space cost is O(1).
        array<int, 26> frequencies{}; // Without {}: garbage init values!
        for (int i = 0; i < s.size(); i++)
        {
            frequencies[s[i] - 'a'] += 1;
            frequencies[t[i] - 'a'] -= 1;
        }

        for (auto f : frequencies)
        {
            if (f != 0)
            {
                return false;
            }
        }

        return true;
    }
};

class Solution_v0
{
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> counts;
        for (auto c : s)
        {
            counts[c] += 1;
        }

        for (auto c : t)
        {
            counts [c] -= 1;
        }

        for (auto [key, value] : counts)
        {
            if (value != 0)
            {
                return false;
            }
        }

        return true;
    }
};