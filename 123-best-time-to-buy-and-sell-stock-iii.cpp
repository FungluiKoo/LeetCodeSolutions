#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        for(auto price: prices){
            sell2 = max(sell2, buy2+price);
            buy2 = max(buy2, sell1-price);
            sell1 = max(sell1, buy1+price);
            buy1 = max(buy1, -price);
        }
        return sell2;
    }
};