// Time 15m. OK.
// Return true if ransomNote can be built using (once) the letters in magazine.
// Constraints: strings of only lowercase letters and length in [1, 10^5].

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Return earlier if ransomNote.size() > magazine.size().

        unordered_map<char, int> frequencies; // JUST USE AN ARRAY!
        for (auto c : ransomNote)
        {
            frequencies[c] -= 1;
        }
        for (auto c : magazine)
        {
            frequencies[c] += 1;
        }
        for (auto [c, frequency] : frequencies)
        {
            if (frequency < 0)
                return false;
        }

        return true;
    }
};