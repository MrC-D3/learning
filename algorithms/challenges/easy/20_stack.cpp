// Time: 20m. Ok.
// Given a string s containing just the characters '(', ')', '{', '}', '[' and 
//  ']', determine if the input string is valid. An input string is valid if:
//  - Open brackets must be closed by the same type of brackets;
//  - Open brackets must be closed in the correct order;
//  - Every close bracket has a corresponding open bracket of the same type.
// Example 1: Input: s = "()" Output: true.

#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isValid(string s) 
    {
        if (s.size() % 2 != 0)
        {
            return false;
        }

        stack<char> open_brackets;
        for(auto c : s)
        {
            switch(c)
            {
                case '{':
                case '[':
                case '(':
                    open_brackets.push(c);
                    break;
                case ')':
                    // If call top() on empty stack: Segmentation fault.
                    if (!open_brackets.empty())
                    {
                        if (open_brackets.top() != '(')
                        {
                            return false;
                        }
                        else
                        {
                            open_brackets.pop();
                        }
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if (!open_brackets.empty())
                    {
                        if (open_brackets.top() != '[')
                        {
                            return false;
                        }
                        else
                        {
                            open_brackets.pop();
                        }
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '}':
                    if (!open_brackets.empty())
                    {
                        if (open_brackets.top() != '{')
                        {
                            return false;
                        }
                        else
                        {
                            open_brackets.pop();
                        }
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }
        }

        if (!open_brackets.empty())
        {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([])") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid(")]") << endl;

    return 0;
}