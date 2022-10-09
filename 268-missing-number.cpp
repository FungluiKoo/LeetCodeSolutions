#include <numeric>
#include <vector>

using namespace std;

class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(auto num: nums){
            result ^= num;
        }
        for(int i=1; i<=n; ++i){
            result ^= i;
        }
        return result;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = ((1+n)*n)>>1;
        return -accumulate(nums.begin(), nums.end(), -s);
    }
};