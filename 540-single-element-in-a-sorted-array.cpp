#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        int left = 0, right = nums.size()-1; // both left, right are even
        if(nums[left]!=nums[left+1]){return nums[left];}
        if(nums[right]!=nums[right-1]){return nums[right];}
        while(left<right-4){
            int middle = ((left+right)>>2)<<1; // middle is even
            if(nums[middle]==nums[middle+1]){
                left = middle;
            }else if(nums[middle]==nums[middle-1]){
                right = middle;
            }else{
                return nums[middle];
            }
        }
        return nums[(left+right)/2];
    }
};