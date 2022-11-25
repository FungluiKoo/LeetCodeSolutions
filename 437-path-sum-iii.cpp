#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    int target;
    unsigned result;
    unordered_map<long long, unsigned> psum;
    void helper(TreeNode *root, long long level){
        if(root==nullptr){return;}
        long long new_level = level + root->val;
        result += psum[new_level - target];
        ++psum[new_level];
        helper(root->left, new_level);
        helper(root->right, new_level);
        --psum[new_level];
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        result = 0u;
        psum.clear();
        psum[0] = 1;
        helper(root, 0);
        return result;
    }
};


class Solution2 {
private:
    unordered_map<long long, unsigned> helper(TreeNode *root, unsigned &cnt, int target){
        unordered_map<long long, unsigned> result;
        if(root==nullptr){return result;}
        auto val = root->val;
        if(val==target){++cnt;}
        result[val] = 1;
        auto left = helper(root->left, cnt, target);
        for(auto [k, v]: left){
            if(k+val==target){cnt += v;}
            result[k+val] += v;
        }
        auto right = helper(root->right, cnt, target);
        for(auto [k, v]: right){
            if(k+val==target){cnt += v;}
            result[k+val] += v;
        }
        return result;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unsigned cnt = 0u;
        helper(root, cnt, targetSum);
        return cnt;
    }
};

