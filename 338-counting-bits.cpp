#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i=1; i<=n; ++i){
            result[i] = (i&0b1) ? (result[i-1] + 1) : result[i>>1];
        }
        return result;
    }
};