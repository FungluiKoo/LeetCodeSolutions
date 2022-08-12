#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto iter = prices.cbegin();
        auto prev_price = *iter;
        int result = 0;
        for(++iter; iter!=prices.cend(); ++iter){
            if(*iter > prev_price){
                result += *iter - prev_price;
            }
            prev_price = *iter;
        }
        return result;
    }
};