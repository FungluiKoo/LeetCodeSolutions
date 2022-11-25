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
    bool helper(TreeNode *root, int target){
        if(root->left==nullptr && root->right==nullptr){return target==root->val;}
        return (root->left && helper(root->left, target-root->val)) ||\
               (root->right && helper(root->right, target-root->val));
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return root && helper(root, targetSum);
    }
};