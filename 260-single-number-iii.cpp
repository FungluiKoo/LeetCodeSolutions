#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xx = 0;
        for(auto num:nums){
            xx ^= num;
        }
        unsigned mask = 1u;
        while((xx&mask)==0){mask<<=1u;}
        int a=0, b=0;
        for(auto num:nums){
            if(num&mask){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return {a,b};
    }
};