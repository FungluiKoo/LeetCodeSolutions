#include <vector>

using namespace std;

class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for(auto x:nums){
            ++cnt[x];
        }
        auto it = nums.begin();
        for(int x=0; x<3; ++x){
            for(int i=0; i<cnt[x]; ++i){
                *(it++) = x;
            }
        }
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int left=0, mid=0, right = nums.size()-1;
        while(mid<=right){
            switch (nums[mid]){
            case 0:
                swap(nums[left++],nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid],nums[right--]);
                break;
            default:
                break;
            }
        }
    }
};