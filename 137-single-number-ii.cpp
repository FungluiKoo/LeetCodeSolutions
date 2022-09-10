#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32; ++i){
            int bitmask = 1<<i;
            int count = 0;
            for(auto &num:nums){
                if(num&bitmask){++count;}
            }
            if(count%3){result |= bitmask;}
        }
        return result;
    }
};