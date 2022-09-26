#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){return a[1]<b[1];});
        int endtime = -__INT_MAX__;
        int cnt = 0;
        for(auto &pair: pairs){
            if(pair[0]>endtime){
                ++cnt;
                endtime = pair[1];
            }
        }
        return cnt;
    }
};