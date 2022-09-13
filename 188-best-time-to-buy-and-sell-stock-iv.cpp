#include <queue>
#include <stack>
#include <vector>

using namespace std;


// Reference: O(n lg n) https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54118/C%2B%2B-Solution-with-O(n-%2B-klgn)-time-using-Max-Heap-and-Stack
// O(n lg k) https://leetcode.wang/leetcode-188-Best-Time-to-Buy-and-Sell-StockIV.html#%E9%A2%98%E7%9B%AE%E6%8F%8F%E8%BF%B0%EF%BC%88%E5%9B%B0%E9%9A%BE%E9%9A%BE%E5%BA%A6%EF%BC%89
class Solution {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> profits;
    void pushProfit(int profit){
        if(profits.size()<k){
            profits.push(profit);
        }else if(profits.top()<profit){
            profits.pop();
            profits.push(profit);
        }
    }
    int maxProfitunlimited(vector<int>& prices) { // LeetCode 122
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
public:
    int maxProfit(int k, vector<int>& prices) {
        this->k = k;
        int n = prices.size();
        if(2*k>=n){return maxProfitunlimited(prices);}
        int v = 0, p = 0;
        stack<pair<int,int>> S; // buy-sell prices
        while(true){
            for(v = p; v+1<n && prices[v+1]<=prices[v]; ++v){}
            for(p = v; p+1<n && prices[p+1]>=prices[p]; ++p){}
            if(p==v){break;}
            int buy_price = prices[v], sale_price = prices[p];
            while(!S.empty() && buy_price<S.top().first){
                pushProfit(S.top().second-S.top().first);
                S.pop();
            }
            while(!S.empty() && sale_price>=S.top().second){
                pushProfit(S.top().second-buy_price);
                buy_price = S.top().first;
                S.pop();
            }
            S.push({buy_price, sale_price});
        }
        while(!S.empty()){
            pushProfit(S.top().second - S.top().first);
            S.pop();
        }
        int result = 0;
        while(!profits.empty()){
            result += profits.top();
            profits.pop();
        }
        return result;
    }
};