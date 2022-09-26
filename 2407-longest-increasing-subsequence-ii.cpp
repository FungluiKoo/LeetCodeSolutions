#include <algorithm>
#include <iostream>
#include <vector>
#include "segment-tree.hh"

using namespace std;

struct mymax{
    int operator()(int a, int b) const{
        return max(a,b);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        segment_tree<int, mymax> cnt(100001);
        int result = 1;
        for(auto num: nums){
            auto c = cnt.query(max(0,num-k), num-1);
            cnt.update(num, c+1);
            result = max(result, c+1);
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    cout << sol.lengthOfLIS(nums,10) << endl;
    return 0;
}