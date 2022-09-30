#include <string>

using namespace std;

// Python would be much easier...
// class Solution:
//     def addStrings(self, num1: str, num2: str) -> str:
//         return str(eval(num1+"+"+num2))


class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        int n = max(n1,n2)+1;
        num1 = string(n-n1,'0') + num1;
        num2 = string(n-n2,'0') + num2;
        string result(n,'0');
        int carryover = 0;
        for(int i=n-1; i>=0; --i){
            int x = carryover + (num1[i]-'0') + (num2[i]-'0');
            carryover = x/10;
            result[i] = '0'+(x%10);
        }
        int i=0;
        while(i<n-1 && result[i]=='0'){++i;}
        return result.substr(i,n-i);
    }
};

class Solution_bad {
private:
    int str2int(string num){
        int n = 0;
        for(auto ch:num){
            n = n*10 + (ch-'0');
        }
        return n;
    }
public:
    string addStrings(string num1, string num2) {
        return to_string(str2int(num1)+str2int(num2));
    }
};