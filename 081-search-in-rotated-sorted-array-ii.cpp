#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(nums[left]==target || nums[right]==target){return true;}
        while(left<right-1){
            int middle = (left+right)/2;
            if(nums[middle]==target){return true;}
            if(nums[left]<nums[middle] || nums[middle]>nums[right]){ // left sorted
                if(nums[left]<target && target<nums[middle]){ // target on left
                    return binary_search(nums.cbegin()+left, nums.cbegin()+middle+1, target);
                }else{ // target on right
                    left = middle;
                }
            }else if(nums[middle]<nums[right] || nums[left]>nums[middle]){ // right sorted
                if(nums[middle]<target && target<nums[right]){ // target on right
                    return binary_search(nums.cbegin()+middle, nums.cbegin()+right+1, target);
                }else{ // target on left
                    right = middle;
                }
            }else{ // nums[left]==nums[middle]==nums[right]
                if(nums[++left]==target || nums[--right]==target){return true;}
            }
        }
        return (nums[left]==target) || (nums[right]==target);
    }
};