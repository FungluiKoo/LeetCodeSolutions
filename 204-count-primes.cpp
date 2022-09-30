#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){return 0;}
        vector<bool> isPrime(n, true);
        int cnt = 1;
        int i=3;
        int sq = ceil(sqrt(n));
        for(; i<=sq; i+=2){
            if(isPrime[i]){
                ++cnt;
                for(int x=i*i; x<n; x+=(i<<1)){
                    isPrime[x] = false;
                }
            }
        }
        for(; i<n; i+=2){
            if(isPrime[i]){
                ++cnt;
            }
        }
        return cnt;
    }
};