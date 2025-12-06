// Time 15m. OK.
// Return true if s is a palindrome, after converting to only lower case letters
//  and removing non-alphanumeric chars.
// Constraints: s.size in [1, 2*10^5].
// Example of palindromes: "A man, a plan, a canal: Panama"; " ".

#include <string>
#include <cctype> // For isalnum() and tolower().

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s) 
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) // Case i == j is useless to check.
        {
            // Find next alphanumeric character from both sides.
            //  Remember to not go outside [0, N-1], that can be achieved not
            //  making i and j cross each other.
            for ( ; i < j && !isalnum(s[i]); i++);
            for ( ; j > i && !isalnum(s[j]); j--);

            // If not palindrome so far, don't continue.
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }

            // So far, palindrome: keep increasing and decreasing.
            i++;
            j--;
        }

        return true;
    }
};

class Solution_v0
{
public:
    bool isPalindrome(string s) 
    {
        int j = s.size() - 1;
        int i = 0;
        for (; i < s.size(); i++)
        {
            if (!isalnum(s[i]))
            {
                continue;
            }

            // is alpha.
            s[i] = tolower(s[i]);
            for ( ; j >= 0; j--)
            {
                if (!isalnum(s[j]))
                {
                    continue;
                }

                // is alpha.
                s[j] = tolower(s[j]);
                if (s[i] != s[j])
                {
                    return false;
                }
                j--;
                break;
            }
        }

        if (i != s.size())
        {
            return false;
        }

        return true;
    }
};

int main()
{
    return 0;
}