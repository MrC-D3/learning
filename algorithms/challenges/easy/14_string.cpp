// Time: 20m.
// Return the longest prefix among a group of strings.
// Constraints: strs.size in [1, 200]; strs[i].size in [0, 200]; only lowercase
//  letters or empty string.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// O(N*M), where M is strs[i].size().
class Solution
{
public:
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

// Sorting the vector you can compare the first string and the last one, but
//  sorting costs M*NlogN, so you lose the advantage.
class Solution_v0 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        auto first = *(strs.begin());
        auto last = *(strs.rbegin());
        string result;
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] == last[i])
                result.push_back(first[i]);
            else
                break;
        }

        return result;
    }
};