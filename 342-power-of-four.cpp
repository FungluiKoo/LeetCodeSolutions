using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1){return false;}
        while(n>1){
            if(n&0b11){return false;}
            n >>= 2;
        }
        return true;
    }
};