#include <string>
#include <unordered_map>
#include <array>


using namespace std;

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        // Constraints say: s and t consist of lowercase English letters.
        //  So, no need of an hash map: an array is fine.
        array<int, 26> counts{0};

        for (auto c : s)
        {
            counts[c - 'a'] += 1;
        }
        for (auto c : t)
        {
            counts[c - 'a'] -= 1;
        }

        for (auto count : counts)
        {
            if (count != 0)
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