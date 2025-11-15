// Time: 20m. Ok.
// Convert a roman numerals in classic numerals.
// Constraints: result always in [1, 3999].

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // More memory, but fixed size, so space cost still O(1).
        // For same reason and for faster lookup, even an int[128] can be used.
        const unordered_map<char, int> roman2classic{
          {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, 
          {'M', 1000}};

        int result = 0;
        int prev_value = 4000;
        for (auto c : s)
        {
            auto to_sum = roman2classic[c];
            if (prev_value < to_sum)
                result -= (prev_value*2);
            result += to_sum;
            prev_value = to_sum;
        }
        return result;
    } 
};

class Solution_v0 {
public:
    int romanToInt(string s) {
        int result = 0;
        int prev_value = 4000;
        for (auto c : s)
        {
            switch(c)
            {
                case 'I':
                    result += 1;
                    prev_value = 1;
                    break;
                case 'V':
                    if (prev_value == 1)
                        result -= 2;
                    result += 5;
                    prev_value = 5;
                    break;
                case 'X':
                    if (prev_value == 1)
                        result -= 2;
                    result += 10;
                    prev_value = 10;
                    break;
                case 'L':
                    if (prev_value == 10)
                        result -= 20;
                    result += 50;
                    prev_value = 50;
                    break;
                case 'C':
                    if (prev_value == 10)
                        result -= 20;
                    result += 100;
                    prev_value = 100;
                    break;
                case 'D':
                    if (prev_value == 100)
                        result -= 200;
                    result += 500;
                    prev_value = 500;
                    break;
                case 'M':
                    if (prev_value == 100)
                        result -= 200;
                    result += 1000;
                    prev_value = 1000;
                    break;
                default:

            }
        }
        return result;
    } 
};