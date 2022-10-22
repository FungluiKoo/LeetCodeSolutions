#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<int,vector<int>,greater<int>> sellq; // minheap
        unordered_map<int,uint64_t> sellcnt;
        priority_queue<int> buyq; // maxheap
        unordered_map<int,uint64_t> buycnt;
        for(const auto &order : orders){
            auto price = order[0];
            uint64_t amt = order[1];
            if(order[2]==0){ // buy order
                while(amt&&!sellq.empty()&&sellq.top()<=price){
                    if(amt>=sellcnt[sellq.top()]){
                        amt -= sellcnt[sellq.top()];
                        sellcnt[sellq.top()] = 0u;
                        sellq.pop();
                    }else{
                        sellcnt[sellq.top()] -= amt;
                        amt = 0;
                    }
                }
                if(amt){
                    if(buycnt[price]){
                        buycnt[price] += amt;
                    }else{
                        buyq.push(price);
                        buycnt[price] = amt;
                    }
                }
            }else{ // sell order
                while(amt&&!buyq.empty()&&buyq.top()>=price){
                    if(amt>=buycnt[buyq.top()]){
                        amt -= buycnt[buyq.top()];
                        buycnt[buyq.top()] = 0u;
                        buyq.pop();
                    }else{
                        buycnt[buyq.top()] -= amt;
                        amt = 0;
                    }
                }
                if(amt){
                    if(sellcnt[price]){
                        sellcnt[price] += amt;
                    }else{
                        sellq.push(price);
                        sellcnt[price] = amt;
                    }
                }
            }
        }
        uint64_t result = 0u;
        for(auto [price,cnt] : sellcnt){
            result += cnt;
            result %= 1000000007u;
        }
        for(auto [price,cnt] : buycnt){
            result += cnt;
            result %= 1000000007u;
        }
        return int(result);
    }
};