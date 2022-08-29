#include <string>
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
    vector<string> sols;
    vector<int> path;
    void addpath(){
        if(path.size()==0){return;}
        auto ans = to_string(path[0]);
        for(int i=1; i<path.size(); ++i){
            ans += "->";
            ans += to_string(path[i]);
        }
        sols.push_back(ans);
    }
    void backtrack(TreeNode* curr){
        path.push_back(curr->val);
        if(curr->left){backtrack(curr->left);}
        if(curr->right){backtrack(curr->right);}
        else if(curr->left==nullptr){addpath();}
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        backtrack(root);
        return sols;
    }
};