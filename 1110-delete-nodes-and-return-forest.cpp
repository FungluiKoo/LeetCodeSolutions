#include <unordered_set>
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
    vector<TreeNode*> result;
    unordered_set<int> filter;
    void helper(TreeNode *root, bool initial){
        if(filter.count(root->val)){
            if(root->left){helper(root->left, true);}
            if(root->right){helper(root->right, true);}
            return;
        }
        if(initial){result.push_back(root);}
        if(root->left){
            helper(root->left, false);
            if(filter.count(root->left->val)){root->left = nullptr;}
        }
        if(root->right){
            helper(root->right, false);
            if(filter.count(root->right->val)){root->right = nullptr;}
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        result.clear();
        filter.clear();
        for(auto x: to_delete){
            filter.insert(x);
        }
        if(root){helper(root, true);}
        return result;
    }
};