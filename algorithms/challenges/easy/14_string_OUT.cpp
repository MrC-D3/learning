// Time: 20m. First time was ok, but didn't check the time!
// Return the longest prefix among a group of strings.
// Constraints: strs.size in [1, 200]; strs[i].size in [0, 200]; only lowercase
//  letters or empty string.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution // O(N*M), where M is strs[i].size().
{
public:
    // No cost advantage in sorting the strings, because true that you can just
    //  just compare 1st and last strings, but sorting costs M*NlogN anyway.
    string longestCommonPrefix(vector<string>& strs) 
    {
        string to_return = strs[0];
        // A for-range would read strs[0] again.
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < min(to_return.size(), strs[i].size()) 
              && to_return[j] == strs[i][j])
            {
                j++;
            }

            to_return.resize(j);
        }

        return to_return;
    }
};
