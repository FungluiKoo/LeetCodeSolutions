#include <algorithm>
#include <random>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums): nums(nums) {}
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> result(nums);
        random_device rd;
        mt19937 g(rd());
        std::shuffle(result.begin(), result.end(), g);
        return result;
    }

    vector<int> shuffle2() {
        int n = nums.size();
        if(n==0){return {};}
        vector<int> result(nums);
        for(int i=n-1; i>=0; --i){
            swap(result[i], result[rand()%(i+1)]);
        }
        return result;
    }
};