#include <unordered_set>
#include <vector>

using namespace std;

struct hashFunc{ // https://www.geeksforgeeks.org/unordered-set-of-vectors-in-c-with-examples/
  size_t operator()(const vector<int> 
                    &myVector) const 
  {
    std::hash<int> hasher;
    size_t answer = 0;
      
    for (int i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};

class Solution {
private:
    vector<int> nums;
    unordered_set<vector<int>, hashFunc> sols;
    void helper(int level){
        if(level==nums.size()-1){
            sols.insert(nums);
            return;
        }
        for(int i=level; i<nums.size(); ++i){
            swap(nums[i],nums[level]);
            helper(level+1);
            swap(nums[i],nums[level]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        helper(0);
        vector<vector<int>> result;
        for(auto &v:sols){
            result.push_back(v);
        }
        return result;
    }
};

int main(){
    Solution sol;
    return 0;
}