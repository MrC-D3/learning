// Time: not in Grind75, so - since it asks for a known algorithm - assume 15m.
// Return the index of the first occurrence of needle in haystack, or -1 if not
//  found.
// Input: haystack = "sadbutsad", needle = "sad" Output: 0
//  Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index
//  0, so we return 0.

#include <string>
#include <vector>

using namespace std;

// KMP (Knuth-Morris-Prat) algorithm: O(m+n), where m=needle.size and 
//  n=haystack.size.
// The algorithm ensures:
// - no backtrack in haystack reading;
// - potentially less backtrack in needle reading, if repeated chars.
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size();
        int m = needle.size();

        // Build the Longest Prefix-Suffix (LPS) vector, i.e. store for the 
        //  string that ends in needle[i] the length of the longest prefix that 
        //  is also a suffix (don't count the whole string). 
        // O(2m), because i_lps can reach the end and then go back to the start.
        // Notes: equivalent to store the index of the next character after that 
        //  prefix.
        vector<int> lps(m);
        for (int i_lps = 0, i = 1; i < m; )
        {
            if (needle[i] == needle[i_lps])
            {
                lps[i++] = ++i_lps;
            }
            else if (i_lps > 0)
            {
                // Storing the length of LPS means storing also the first index
                //  after that LPS, because the LPS is (also) a prefix, so that
                //  length starts from 0.
                // Mismatch here is similar to mismatch in search phase: 
                //  instead of restarting from 0, you restart from 
                //  E=lps[i_lps-1], because you know that till [i_lps-1] first E
                //  chars were Equal to last E chars, so you don't need to check
                //  them again and you move the compare window from [E] on.
                i_lps = lps[i_lps - 1]; // Good tests: ABABB, ABABAC.
            }
            else
            {
                lps[i++] = 0; // Actually already 0, but i++ is important.
            }
        }

        // Use the LPS to find the substring: O(n), so in total O(2m+n)=O(m+n).
        for (int i = 0, j = 0; j < n; )
        {
            if (needle[i] == haystack[j])
            {
                i++;
                j++;
                if (i == m)
                    return j - i;
            }
            else if (i > 0)
            {
                // From haystack's point-of-view, if mismatch in naive solution,
                //  the compare windows shifts by 1; here, it shifts by 
                //  E=lps[i-1], i.e. by the LPS's size till the point where the 
                //  strings matched.
                // From needle's POV, you know there was a match till [i-1] and
                //  - in that matched substring - the first E chars are Equal to
                //  the last E chars, so now you consider those last E chars the
                //  first E chars and you resume the comparison from [E].
                i = lps[i - 1];
            }
            else
            {
                ++j;
            }
        }

        return -1;
    }
};

// Library based.
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        return haystack.find(needle);
    }
};