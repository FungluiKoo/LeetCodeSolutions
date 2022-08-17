#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<short,int> cnt;
        int max_cnt = 0;
        for(short x:nums){
            if(cnt.count(x)){
                ++cnt[x];
            }else{
                cnt[x] = 1;
            }
            max_cnt = max(cnt[x],max_cnt);
        }
        vector<vector<short>> inv(max_cnt+1);
        for(auto x:cnt){
            inv[x.second].push_back(x.first);
        }
        vector<int> result;
        for(auto it=inv.rbegin(); it!=inv.rend() && result.size()<k; ++it){
            for(auto number:*it){
                result.push_back(number);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<short,int> cnt;
        for(short x:nums){
            if(cnt.count(x)){
                ++cnt[x];
            }else{
                cnt[x] = 1;
            }
        }
        multimap<int,short> inv;
        for(auto x:cnt){
            inv.insert({x.second,x.first});
        }
        vector<int> result;
        auto it=inv.rbegin();
        for(int i=0; i<k; ++i){
            result.push_back((it++)->second);
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2};
    for(auto x:sol.topKFrequent(nums,2)){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}