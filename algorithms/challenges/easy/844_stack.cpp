// Time: 15m. OUT.
// Return true if 2 strings produce the same output on an editor, where # is
//  considered a backspace.
// Constraints: 

#include <string>
#include <stack>
#include <array>

using namespace std;

// O(1) space: the stack logic is implicit.
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i_s = s.size() - 1;
        int i_t = t.size() - 1;
        while (i_s >= 0 && i_t >= 0)
        {
            int skip_count = 0;
            for ( ; i_s >= 0 && skip_count >= 0; i_s--)
            {
                if (s[i_s] == '#')
                    skip_count++;
                else
                    skip_count--;
            }
            skip_count = 0;
            for ( ; i_t >= 0 && skip_count >= 0; i_t--)
            {
                if (t[i_t] == '#')
                    skip_count++;
                else
                    skip_count--;
            }

            if ((i_s < 0 && i_t >= 0) || (i_s >= 0 && i_t < 0))
                return false;
            if (i_s >= 0 && i_t >= 0 && s[i_s] != t[i_t])
                return false;

            i_s -= 1;
            i_t -= 1;
        }

        return true;
    }
};

class Solution_v0 {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stack_s, stack_t;

        // Put this for() in a function since it repeats.
        for (auto c : s)
        {
            if (c == '#')
            {
                if (!stack_s.empty())
                    stack_s.pop();
            }
            else
                stack_s.push(c);
        }
        for (auto c : t)
        {
            if (c == '#')
            {
                if (!stack_t.empty())
                    stack_t.pop();
            }
            else
                stack_t.push(c);
        }

        // You can directly compare 2 stacks instead of looping on them.
        if (stack_s.size() != stack_t.size())
            return false;
        while (stack_s.size() > 0)
        {
            if (stack_s.top() != stack_t.top())
                return false;
            stack_s.pop();
            stack_t.pop();
        }

        return true;
    }
};