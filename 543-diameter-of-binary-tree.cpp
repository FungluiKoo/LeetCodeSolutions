#include <algorithm>

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
    int helper(TreeNode *root, int &diameter){
        if(root==nullptr){return 0;}
        auto left = helper(root->left, diameter);
        auto right = helper(root->right, diameter);
        diameter = std::max(diameter, left + right);
        return 1 + std::max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        helper(root, result);
        return result;
    }
};