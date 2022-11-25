#include <vector>

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
    int psum;
    vector<int> path;
    vector<vector<int>> result;
    void helper(TreeNode *root, int target){
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && target==root->val){
            result.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left){
            helper(root->left, target-root->val);
        }
        if(root->right){
            helper(root->right, target-root->val);
        }
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        psum = 0;
        path.clear();
        result.clear();
        if(root){helper(root, targetSum);}
        return result;
    }
};