#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<=100){return *min_element(nums.cbegin(), nums.cend());}
        int left = 1, right = nums.size()-1;
        int pivot = nums[0];
        if(nums[left]<pivot){return nums[left];}
        if(nums[right]>pivot){return pivot;}
        while(left<right-1){
            int middle = (left+right)/2;
            if(nums[middle]<pivot){
                right = middle;
            }else if(nums[middle]>pivot){
                left = middle;
            }else{ // nums[middle]==pivot
                if(nums[left]>pivot){
                    right = middle;
                }else if(nums[right]<pivot){
                    left = middle;
                }else{ // nums[left]==nums[middle]==nums[right]
                    if(nums[left]>nums[left+1]){return nums[left+1];}
                    ++left;
                    if(nums[right-1]>nums[right]){return nums[right];}
                    --right;
                }
            }
        }
        return nums[right];
    }
};