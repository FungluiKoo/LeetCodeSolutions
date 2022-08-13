using namespace std;

class Solution1 {
public:
    int mySqrt(int x) {
        if(x<=1){return x;}
        unsigned long long left = 1, middle = 0, right = x;
        while(left<right-1){
            middle = (left+right)/2;
            if(middle*middle>(unsigned long long)x){right = middle;}
            else if(middle*middle==(unsigned long long)x){return middle;}
            else{left = middle;}
        }
        return left;
    }
};

class Solution2 {
public:
    int mySqrt(int x) {
        unsigned long long s = x;
        while(s*s>(unsigned long long)x){
            s = (s + x/s)/2;
        }
        return s;
    }
};