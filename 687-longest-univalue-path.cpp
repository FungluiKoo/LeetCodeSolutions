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
    unsigned result;
    vector<pair<int, unsigned>> path;
    void helper(TreeNode *root, unsigned depth){
        path.push_back({root->val, depth});
        for(auto it=path.rbegin(); it!=path.rend() && it->first==root->val; ++it){
            it->second = std::max(it->second, depth);
        }
        unsigned length = 0u;
        // visit left subtree
        if(root->left){
            helper(root->left, depth+1u);
            length += path.rbegin()->second - depth;
            path.rbegin()->second = depth;    
        }
        // visit right subtree
        if(root->right){
            helper(root->right, depth+1u);
            length += path.rbegin()->second - depth;
        }
        result = std::max(result, length);
        path.pop_back();
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        result = 0u;
        path.clear();
        if(root){helper(root, 0u);}
        return result;
    }
};