#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = nums[0];
        for(int i=1; i<nums.size(); ++i){
            int temp = max(prev+nums[i], curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};