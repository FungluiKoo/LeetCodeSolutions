#include <vector>

using namespace std;

class Solution { // Boyer-Moore Voting Algorithm
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, cnt = 0;
        for(auto num:nums){
            if(cnt==0){
                major = num;
                ++cnt;
            }else{
                cnt += (major==num)? 1 : -1;
            }
        }
        return major;
    }
};