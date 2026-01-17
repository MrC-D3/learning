// Time: 15m.
// Return the sum of 2 binary strings as binary string.
// Constraints: no leading 0s, a.size and b.size in [1, 10^4].

#include <string>
#include <algorithm>

using namespace std;

class Solution { // Reduce duplicated code and simplify the logic.
public:
    string addBinary(string a, string b) {
        string sum;
        int carry = 0;
        auto it_a = a.rbegin();
        auto it_b = b.rbegin();
        while (it_a != a.rend() || it_b != b.rend() || carry != 0)
        {
            auto current_sum = carry;
            if (it_a != a.rend())
            {
                current_sum += (*it_a - '0');
                it_a++;
            }
            if (it_b != b.rend())
            {
                current_sum += (*it_b - '0');
                it_b++;
            }
            sum.push_back( '0' + (current_sum % 2) );
            carry = current_sum / 2; // Or >> 1.
        }

        reverse(sum.begin(), sum.end());
        return sum;
    }
};

class Solution_v2 { // Standard solution.
public:
    string addBinary(string a, string b) {
        int ia = a.size() - 1;
        int ib = b.size() - 1;
        string result;

        int carry = 0;
        for ( ; ia >= 0 && ib >= 0; ia--, ib--)
        {
            auto bit_sum = (a[ia] - '0') + (b[ib] - '0') + carry;
            auto bit = bit_sum % 2;
            carry = bit_sum / 2;
            result.push_back('0' + bit);
        }

        // If a is longer than b.
        for ( ; ia >= 0; ia--)
        {
            auto bit_sum = (a[ia] - '0') + carry;
            auto bit = bit_sum % 2;
            carry = bit_sum / 2;
            result.push_back('0' + bit);
        }
        // If b is longer than a.
        for ( ; ib >= 0; ib--)
        {
            auto bit_sum = (b[ib] - '0') + carry;
            auto bit = bit_sum % 2;
            carry = bit_sum / 2;
            result.push_back('0' + bit);
        }
        // If result is longer than both.
        if (carry != 0)
            result.push_back('1');

        reverse(result.begin(), result.end());
        return result;
    }
};

// Don't check which string is the shortest.
class Solution_v1 {
public:
    string addBinary(string a, string b) {
        string sum;
        char carry = '0';

        auto it_a = a.rbegin();
        auto it_b = b.rbegin();
        while (it_a != a.rend() || it_b != b.rend())
        {
            auto current_bit = carry;
            carry = '0';
            if (it_a != a.rend() && *it_a == '1')
            {
                if (current_bit == '0')
                {
                    current_bit = '1';
                }
                else
                {
                    current_bit = '0';
                    carry = '1';
                }
                it_a++;
            }
            if (it_b != b.rend() && *it_b == '1')
            {
                if (current_bit == '0')
                {
                    current_bit = '1';
                }
                else
                {
                    current_bit = '0';
                    carry = '1';
                }
                it_b++;
            }

            sum.push_back(current_bit);
        }

        if (carry == '1')
        {
            sum.push_back(carry);
        }

        reverse(sum.begin(), sum.end());
        return sum;
    }
};

 // Don't use the delta offset thanks to the reverse iterators.
class Solution_v0 {
public:
    string addBinary(string a, string b) {
        // Find the longest and the shortest.
        string sum{a}; // 11
        string shortest{b}; // 1
        if (a.size() < b.size())
        {
            sum = b;
            shortest = a;
        }

        // Loop.
        char report = '0';
        auto it_sum = sum.rbegin();
        for (auto it = shortest.rbegin(); it != shortest.rend(); it++)
        {
            if (report == '1')
            {
                if (*it_sum == '1')
                {
                    *it_sum = '0';
                }
                else
                {
                    *it_sum = '1';
                    report = '0';
                }
            }
            if (*it == '1')
            {
                if (*it_sum == '1')
                {
                    *it_sum = '0';
                    report = '1';
                }
                else
                {
                    *it_sum = '1';
                }
            }

            it_sum++;
        }

        // Add the remaining bits from the longest, i.e. [delta, 0].
        for (; it_sum != sum.rend(); it_sum++)
        {
            if (report == '1')
            {
                if (*it_sum == '1')
                {
                    *it_sum = '0';
                }
                else
                {
                    *it_sum = '1';
                    report = '0';
                }
            }
        }

        if (report == '1')
        {
            sum = "1" + sum;
        }
        
        return sum;
    }
};
