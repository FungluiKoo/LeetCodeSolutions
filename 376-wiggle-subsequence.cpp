#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        switch (n){
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return (nums[0]==nums[1]) ? 1 : 2;
        default:
            break;
        }
        int result = 1, prev = nums[0];
        int i = 1;
        while(i<n && nums[i]==nums[0]){++i;}
        while(i<n){
            ++result;
            bool up = (nums[i]>nums[i-1]);
            if(up){
                while(++i<n && nums[i]>=nums[i-1]){} 
            }else{
                while(++i<n && nums[i]<=nums[i-1]){} 
            }
        }
        return result;
    }
};