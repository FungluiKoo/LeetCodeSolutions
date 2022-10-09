#include <vector>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit=n&0b1;
        while(n>>=1){
            if((n&0b1)==bit){return false;}
            bit = n&0b1;
        }
        return true;
    }
};