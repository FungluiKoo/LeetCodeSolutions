#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> comb;
    void helper(vector<int>& candidates, int level, int target){
        if(candidates.size()==level){
            if(target==0){result.push_back(comb);}
            return;
        }
        // Option 1: Pick candidates[level]
        if(candidates[level]<=target){
            comb.push_back(candidates[level]);
            helper(candidates, level+1, target-candidates[level]);
            comb.pop_back();
        }
        // Option 2: Not pick
        for(int prev=candidates[level++]; level<candidates.size() && prev==candidates[level]; ++level){}
        helper(candidates, level, target);
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return result;
    }
};