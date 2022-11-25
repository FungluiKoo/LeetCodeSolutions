#include <algorithm>
#include <cmath>

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
    int helper(TreeNode *root){
        // Max depth if balanced; otherwise -1
        if(root==nullptr){return 0;}
        auto left = helper(root->left);
        auto right = helper(root->right);
        return (left<0 || right<0 || std::abs(left-right)>1) ?\
                 -1 : 1 + std::max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return helper(root)>=0;
    }
};