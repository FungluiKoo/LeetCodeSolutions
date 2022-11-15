#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n<2){return n;}
        vector<unsigned> ugly{1};
        vector<unsigned> id(primes.size(), 0);
        priority_queue<pair<unsigned,unsigned>, vector<pair<unsigned,unsigned>>, greater<pair<unsigned,unsigned>>> candidates;
        for(unsigned i=0; i<primes.size(); ++i){
            candidates.push({primes[i], i});
        }
        
        while(ugly.size()<n){
            auto cand = candidates.top().first;
            ugly.push_back(cand);
            while(candidates.top().first==cand){
                auto i = candidates.top().second;
                candidates.pop();
                ++id[i];
                candidates.push({primes[i]*ugly[id[i]], i});
            }
        }
        return ugly[n-1];
    }
};