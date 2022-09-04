#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp = 0, sum = 0;
        for(int i=2; i<nums.size(); ++i){
            if(nums[i-2]+nums[i]==nums[i-1]*2){
                sum += ++dp;
            }else{
                dp = 0;
            }
        }
        return sum;
    }
};