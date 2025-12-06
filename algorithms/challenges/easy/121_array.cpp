// Time: 20m. OK.
// Return the maximum profit you can achieve buying a stock on day [i] and 
//  selling it another day later. Return 0 if any profit.
// Constraints: prices.size in [1, 10^5] and prices[i] in [0, 10^4].

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() == 1)
        {
            return 0;
        }

        int min_price{prices[0]}, to_return{0};
        for (auto price : prices)
        {
            if (price <= min_price)
            {
                min_price = price;
                continue;
            }
            
            to_return = max(to_return, price - min_price);
        }

        return to_return;
    }
};
