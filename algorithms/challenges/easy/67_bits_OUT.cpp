// Time: 15m. OUT.

#include <string>
#include <algorithm>

using namespace std;

class Solution { // Don't use the delta offset thanks to the reverse iterators.
public:
    string addBinary(string a, string b) {
        // Find the longest and the shortest.
        string sum{a};
        string shortest{b};
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
        }

        if (report == '1')
        {
            sum = "1" + sum;
        }
        
        return sum;
    }
};

class Solution_v1 { // Don't use a third string, but directly the string sum.
public:
    string addBinary(string a, string b) {
        // Find the longest and the shortest, then compute the delta-offset.
        string sum{a};
        string shortest{b};
        if (a.size() < b.size())
        {
            sum = b;
            shortest = a;
        }
        auto delta = sum.size() - shortest.size();

        // Loop from min_size to 0 (adding the delta-offset for the longest).
        char report = '0';
        for (int i = shortest.size()-1; i >= 0; i--)
        {
            if (report == '1')
            {
                if (sum[delta+i] == '1')
                {
                    sum[delta+i] = '0';
                }
            }
            if (shortest[i] == '1')
            {
                if (sum[delta+i] == '1')
                {
                    sum[delta+i] = '0';
                    report = '1';
                }
                else
                {
                    sum[delta+i] = '1';
                }
            }
        }

        // Add the remaining bits from the longest, i.e. [delta, 0].
        for (int i = delta-1; i >= 0; i--)
        {
            if (report == '1')
            {
                if (sum[delta+i] == '1')
                {
                    sum[delta+i] = '0';
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

class Solution_v0 {
public:
    string addBinary(string a, string b) {
        string sum;

        // Find the longest and the shortest, then compute the delta-offset.
        string longest{a}, shortest{b};
        if (a.size() < b.size())
        {
            longest = b;
            shortest = a;
        }
        sum = longest;
        auto delta = longest.size() - shortest.size();

        // Loop from min_size to 0 (adding the delta-offset for the longest).
        char report = '0';
        for (int i = shortest.size()-1; i >= 0; i--)
        {
            sum[delta+i] = report;
            report = '0';
            if (shortest[i] == '1')
            {
                if (sum[delta+i] == '1')
                {
                    sum[delta+i] = '0';
                    report = '1';
                }
                else
                {
                    sum[delta+i] = '1';
                }
            }
            if (longest[delta+i] == '1')
            {
                if (sum[delta+i] == '1')
                {
                    sum[delta+i] = '0';
                    report = '1';
                }
                else
                {
                    sum[delta+i] = '1';
                }  
            }
        }

        // Add the remaining bits from the longest, i.e. [delta, 0].
        for (int i = delta-1; i >= 0; i--)
        {
            sum[i] = report;
            report = '0';
            if (longest[i] == '1')
            {
                if (sum[i] == '1')
                {
                    sum[i] = '0';
                    report = '1';
                }
                else
                {
                    sum[i] = '1';
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