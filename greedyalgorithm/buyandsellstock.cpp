#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; // Initialize max profit to 0
        int minPrice = INT_MAX; // Initialize minimum price to a very high value
        
        for (int price : prices) {
            // Update minPrice if the current price is lower than minPrice
            minPrice = min(minPrice, price);
            
            // Calculate profit if we sell at the current price
            int profit = price - minPrice;
            
            // Update maxProfit if the calculated profit is higher
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
