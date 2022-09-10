#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_price = 0, max_profit = 0;
        for(int i=prices.size()-1; i>=0; --i){
            max_price = max(prices[i], max_price);
            max_profit = max(max_price - prices[i], max_profit);
        }
        return max_profit;
    }
};