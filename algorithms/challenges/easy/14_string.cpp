#include <string>
#include <vector>


using namespace std;

class Solution 
{
public:
    // If strs.size() << strs[i].size(), it may be more efficient to sort strs[]
    //  and compare only first and last words.
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