// Time: 15m.
// Return true if 2 strings produce the same output on an editor, where # is
//  considered a backspace.
// Constraints: the 2 strings contains only lowercase letters or #, and their
//  length is in [1, 200].
// Note: this problem can be solved in O(1) space, but with a medium solution
//  without stacks.

#include <string>
#include <stack>
#include <array>

using namespace std;

// Basic: O(n) time, but also O(n) space.
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1 = build_stack(s);
        stack<char> t1 = build_stack(t);
        
        return s1 == t1;
    }
private:
    stack<char> build_stack(const string s)
    {
        stack<char> stack_;
        for (auto c : s)
        {
            if (c != '#')
            {
                stack_.push(c);
            }
            else if (!stack_.empty())
            {
                stack_.pop();
            }
        }
        return stack_;
    }
};