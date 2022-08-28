#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};

class Solution2 { // not good for big ints
public:
    int uniquePaths(int m, int n) {
        unsigned a = min(m-1,n-1);
        unsigned b = (m-1)+(n-1);
        unsigned long long numer = 1ull, denom = 1ull;
        for(unsigned i=0; i<a; ++i){
            numer *= b-i;
            denom *= i+1;
        }
        return numer/denom;
    }
};