#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){return 0;}
        if(coins.empty()){return -1;}
        vector<int> dp(amount+1, __INT_MAX__-1);
        dp[0] = 0;
        for(int i=0; i<coins.size(); ++i){
            for(int v=coins[i]; v<=amount; ++v){
                dp[v] = min(dp[v], dp[v-coins[i]]+1);
            }
        }
        return dp[amount]>amount ? -1 : dp[amount];
    }
};