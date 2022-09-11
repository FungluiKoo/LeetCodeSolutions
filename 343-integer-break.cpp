using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n<4){return n-1;}
        int result = 1;
        while(n>=5){
            n -= 3;
            result *= 3;
        }
        result *= n;
        return result;
    }
};