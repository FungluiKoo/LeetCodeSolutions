#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> result(r, vector<int>(c,__INT_MAX__-1));
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(mat[i][j]==0){result[i][j]=0;}
            }
        }
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(i>0){result[i][j] = min(result[i][j],result[i-1][j]+1);}
                if(j>0){result[i][j] = min(result[i][j],result[i][j-1]+1);}
            }
        }
        for(int i=r-1; i>=0; --i){
            for(int j=c-1; j>=0; --j){
                if(i<r-1){result[i][j] = min(result[i][j],result[i+1][j]+1);}
                if(j<c-1){result[i][j] = min(result[i][j],result[i][j+1]+1);}
            }
        }
        return result;
    }
};