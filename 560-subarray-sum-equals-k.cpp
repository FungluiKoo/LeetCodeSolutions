#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cumulate = 0;
        int result = 0;
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        for(auto num: nums){
            cumulate += num;
            result += cnt[cumulate-k];
            ++cnt[cumulate];
        }
        return result;
    }
};