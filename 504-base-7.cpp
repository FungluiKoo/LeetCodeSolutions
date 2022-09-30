#include <string>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num<0){
            return '-'+convertToBase7(-num);
        }else if(num==0){
            return "0";
        }
        string result;
        while(num){
            char ch = '0'+(num%7);
            result = ch + result;
            num /= 7;
        }
        return result;
    }
};