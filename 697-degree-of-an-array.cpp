#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto x: nums){
            ++cnt[x];
        }
        vector<int> maxnum;
        int maxcnt = 0;
        for(auto [k,v]: cnt){
            if(v>maxcnt){
                maxnum.clear();
                maxnum.push_back(k);
                maxcnt = v;
            }else if(v==maxcnt){
                maxnum.push_back(k);
            }
        }
        int result = nums.size();
        for(auto k: maxnum){
            int left = 0, right = nums.size()-1;
            while(nums[left]!=k){++left;}
            while(nums[right]!=k){--right;}
            result = min(result, right-left+1);
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> v{1,2,2,3,1};
    cout << sol.findShortestSubArray(v) << "\n";
    return 0;
}