#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int to_return = 0;
        unordered_map<char, int> positions;
        int start = 0;
        int i = 0;
        for (; i < s.size(); i++)
        {
            auto c_it = positions.find(s[i]);
            if (c_it == positions.end())
            {
                positions[s[i]] = i;
            }
            else
            {
                if (c_it->second < start)
                {
                    c_it->second = i;
                }
                else
                {
                    to_return = max(to_return, i - start);
                    start = c_it->second + 1;
                    c_it->second = i;
                }
            }
        }

        to_return = max(to_return, i - start);

        return to_return;
    }
};