using namespace std;

class Solution1 {
public:
    bool isPowerOfThree(int n) {
        if(n<1){return false;}
        while(n>1){
            if(n%3){return false;}
            n/=3;
        }
        return true;
    }
};

