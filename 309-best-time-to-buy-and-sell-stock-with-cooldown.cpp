#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){return 0;}
        int buy = -prices[0], sell = 0, cool = 0;
        for(int i=1; i<prices.size(); ++i){
            int prev_buy = buy;
            buy = max(buy, cool-prices[i]);
            cool = max(cool, sell);
            sell = prev_buy + prices[i];
        }
        return max(sell, cool);
    }
};