#include <stack>

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
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){return true;}
        stack<TreeNode*> S;
        S.push(root);
        S.push(root);
        while(!S.empty()){
            auto l = S.top();
            S.pop();
            auto r = S.top();
            S.pop();
            if((l->val != r->val) || ((l->left==nullptr) ^ (r->right==nullptr)) || ((l->right==nullptr)^(r->left==nullptr))){return false;}
            if(l->right){
                S.push(r->left);
                S.push(l->right);
            }
            if(l->left){
                S.push(r->right);
                S.push(l->left);
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){return true;}
        stack<TreeNode*> SL, SR;
        SL.push(root);
        SR.push(root);
        while(!SL.empty() && !SR.empty()){
            auto l = SL.top();
            auto r = SR.top();
            SL.pop();
            SR.pop();
            if((l->val != r->val) || ((l->left==nullptr) ^ (r->right==nullptr)) || ((l->right==nullptr)^(r->left==nullptr))){return false;}
            if(l->right){
                SL.push(l->right);
                SR.push(r->left);
            }
            if(l->left){
                SL.push(l->left);
                SR.push(r->right);
            }
        }
        return true;
    }
};