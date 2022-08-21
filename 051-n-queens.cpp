#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    vector<bool> col, ldiag, rdiag;
    vector<string> ans;
    vector<vector<string>> result;

    void helper(int level){
        if(level==n){
            result.push_back(ans);
            return;
        }
        for(int i=0; i<n; ++i){
            if(col[i] && ldiag[level-i+n-1] && rdiag[level+i]){
                ans[level][i] = 'Q';
                col[i] = false;
                ldiag[level-i+n-1] = false;
                rdiag[level+i] = false;
                helper(level+1);
                ans[level][i] = '.';
                col[i] = true;
                ldiag[level-i+n-1] = true;
                rdiag[level+i] = true;                
            }
        }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        col.resize(n, true);
        ldiag.resize(2*n-1, true);
        rdiag.resize(2*n-1, true);
        ans.resize(n, string(n, '.'));
        helper(0);
        return this->result;
    }
};

int main(){
    int n=1;
    while(true){
        cin >> n;
        if(n<1 || n>9){break;}
        Solution sol;
        auto result = sol.solveNQueens(n);
        int i=0;
        for(auto &ans:result){
            cout << "\nSolution " << ++i << ":\n";
            for(auto &line:ans){cout<<line<<endl;}
        }
    }
    return 0;
}