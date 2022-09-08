#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n<2){return 0;}
        vector<bool> isprime(n+1,true);
        int result = 0;
        for(int i=2; i<=ceil(sqrt(n)); ++i){
            if(isprime[i]){
                while(n%i==0){
                    result += i;
                    n /= i;
                }
                for(int j=i*i; j<=n; j+=i){
                    isprime[j] = false;
                }
            }
        }
        if(n>1){result += n;}
        return result;
    }
};