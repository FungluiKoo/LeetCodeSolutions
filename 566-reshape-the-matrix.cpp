#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int x = mat.size(), y = mat[0].size();
        if(x*y!=r*c){return mat;}
        vector<vector<int>> result(r, vector<int>(c));
        for(int i=0; i<r*c; ++i){
            result[i/c][i%c] = mat[i/y][i%y];
        }
        return result;
    }
};