// Given a string s, return the number of palindromic substrings in it. A string
//  is a palindrome when it reads the same backward as forward. A substring is a
//  contiguous sequence of characters within the string.
// Example: Input: s = "aaa" Output: 6
//  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

#include <string>


using namespace std;

// The number of sub-strings to check is the triangular number of N: N(N+1)/2.
// So, the acceptable solution is O(N^2).
class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int count = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            // Odd-length sub-string.
            for(int j = 1; i - j >= 0 && i + j < s.size(); j++)
            {
                if (s[i-j] != s[i+j])
                {
                    break;
                }
                count += 1;
            }

            // Even-length sub-string.
            if( (i + 1 < s.size()) && (s[i] == s[i+1]) )
            {
                count += 1;

                for(int j = 1; (i - j >= 0) && (i+1 + j < s.size()); j++)
                {
                    if (s[i-j] != s[i+1+j])
                    {
                        break;
                    }
                    count += 1;
                }        
            }
        }

        return count;
    }
};