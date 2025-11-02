// OUT OF TIME.
// This is a 1D DP problem.
// Neet prerequisites: Backtracking <- Trees <- Linked List & Binary Search <---
//  --- Two Pointers <- Arrays & Hashing.


#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int middle = s.size() / 2;
        vector<int> counts(s.size(), 0); // Tells the radius.
        int longest{1};
        int longest_middle;

        // Odd ones.
        bool keep_going = true;
        int i = 0;
        while (keep_going)
        {
            int radius = counts[i];
            if (i - radius < 0 || i + radius >= s.size())
            {
                continue;
            }
            if (s[i-radius] == s[i+radius])
            {
                keep_going = true;
                counts[i] += 1;
                if (counts[i] > longest)
                {
                    longest = counts[i];
                    longest_middle = i;
                }
            }

            i++;
            if (i == s.size())
            {
                keep_going = false;
                i = 0;
            }
        }

        // Even.
        vector<int> counts2(s.size(), 0); // Tells the radius.
        for ()
    }
};