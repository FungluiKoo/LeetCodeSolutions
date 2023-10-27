#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int x = 0;
        while(x<nums.size() && nums[x]<=0){++x;}
        if(x==nums.size()){return 1;}
        x = nums[x];
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]<=0){nums[i]=x;}
        }
        for(int i=0; i<nums.size(); ++i){
            if(auto v = abs(nums[i]); v<=nums.size()){
                nums[v-1] = -abs(nums[v-1]);
            }
        }
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]>0){return i+1;}
        }
        return nums.size()+1;
    }
};

int main(){
    Solution sol;
    vector<int> nums {0};
    cout << sol.firstMissingPositive(nums) << endl;
    return 0;
}