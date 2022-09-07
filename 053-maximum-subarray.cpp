#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, curr = 0;
        for(auto x: nums){
            curr += x;
            if(curr>result){
                result = curr;
            }
            if(curr<0){
                curr = 0;
            }
        }
        return result;
    }
};