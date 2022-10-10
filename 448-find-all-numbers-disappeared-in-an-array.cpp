#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto &num: nums){
            int it = abs(num) - 1;
            if(nums[it]>0){nums[it] = -nums[it];}
        }
        vector<int> result;
        for(int i=0; i<n; ++i){
            if(nums[i]>0){result.push_back(i+1);}
        }
        return result;
    }
};