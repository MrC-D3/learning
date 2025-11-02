#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        std::vector<int> dp(s.size(), -1);
        std::stack<int> indexes;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                indexes.push(i);
            }
            else // ')'
            {
                if (indexes.size() > 0)
                {
                    auto j = indexes.top();
                    indexes.pop();
                    dp[j] = 1;
                    dp[i] = 0;
                }
            }
        }

        int to_return = 0;
        int current_count = 0;
        for(int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == 1)
            {
                current_count += 1;
            }
            else if (dp[i] == -1)
            {
                to_return = std::max(to_return, current_count);
                current_count = 0;
            }
        }
        to_return = std::max(to_return, current_count);

        return to_return*2;
    }
};


class Solution_official // Space O(1).
{
public:
    int longestValidParentheses(string s) 
    {
        std::stack<int> indexes;

        // Case ')' always pops, so it must find something if s[0]==')'.
        // But not anything, because of how length is compute: i-indexes.top().
        // Putting -1 is perfect for when maxLen is s.size().
        indexes.push(-1);

        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '(') 
            {
                indexes.push(i);
            } 
            else // ')'.
            {
                indexes.pop(); // Closing a pair.
                if (indexes.empty()) 
                {
                    // Re-push something in case next char is ')'.
                    // But not everything, because of how length is computed.
                    // Not -1, but this index works as the new -1.
                    indexes.push(i);
                } 
                else 
                {
                    maxLen = std::max(maxLen, i - indexes.top());
                }
            }
        }

        return maxLen;
    }
};