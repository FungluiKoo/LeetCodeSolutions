#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto num: nums){
            ++cnt[num];
        }
        int result = 0;
        for(auto [k,v]: cnt){
            if(cnt.count(k+1)){
                result = max(v+cnt[k+1], result);
            }
        }
        return result;
    }
};