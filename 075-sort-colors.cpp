#include <vector>

using namespace std;

class Solution {
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