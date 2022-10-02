#include <stack>

using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
private:
    stack<int> s;
    void generate(){
        int x = 0; // 0 to 117648, 7^6=117649
        for(int i=0; i<6; ++i){
            x *= 7;
            x += (rand7()-1);
        }
        int n = 0;
        if(x<100000){ // generates 5 base10 nums
            n = 5;
        }else if(x<110000){
            n = 4;
        }else if(x<117000){
            n = 3;
        }else if(x<117600){
            n = 2;
        }else if(x<117640){
            n = 1;
        }
        for(int i=0; i<n; ++i){
            s.push((x%10)+1);
            x /= 10;
        }
    }
public:
    int rand10() {
        while(s.empty()){generate();}
        int res = s.top();
        s.pop();
        return res;
    }
};