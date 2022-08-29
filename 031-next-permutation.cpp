#include <algorithm>
#include <vector>

using namespace std;

class Solution { // O(n)
public:
    // next_permutation(nums.begin(),nums.end());
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){--i;}
        int j=n-1;
        if(i>=0){
            while(j>i && nums[i]>=nums[j]){--j;}
            swap(nums[i],nums[j]);
            j=n-1;
        }
        for(++i; i<j; ++i, --j){
            swap(nums[i],nums[j]);
        }
    }
};

class Solution2 { // O(n^2)
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-2; i>=0; --i){
            for(int j=n-1; j>i; --j){
                if(nums[i]<nums[j]){
                    swap(nums[i],nums[j]);
                    sort(nums.begin()+i+1,nums.end());
                    return;
                }
            }
        }
        // reversed-sorted
        for(int i=0, j=n-1; i<j; ++i,--j){
            swap(nums[i],nums[j]);
        }
    }
};