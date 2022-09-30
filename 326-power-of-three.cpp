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

class Solution2 {
public:
    bool isPowerOfThree(int n) {
        return (n>0) && (1162261467%n==0);
    }
};