#include <vector>

using namespace std;

class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<2){return;}
        for(int i=0; i<n/2; ++i){
            for(int j=0; j<=(n-1)/2; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<2){return;}
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                matrix[j][n-1-i] |= ((matrix[i][j] & 1023) << 11);
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                matrix[i][j] >>= 11;
            }
        }
    }
};