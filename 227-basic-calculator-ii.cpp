#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int muldiv(string s){
        int result = 1;
        int i = 0; 
        while(i<s.length()){
            int eval = 0, start = i;
            ++i;
            while(i<s.length() && s[i]!='*' && s[i]!='/'){
                if(s[i]!=' '){
                    eval *= 10;
                    eval += (s[i]-'0');
                }
                ++i;
            }
            if(s[start]=='*'){
                result *= eval;
            }else{
                result /= eval;
            }    
        }
        return result;
    }
    int addminus(string s){
        int result = 0;
        int i = 0;
        while(i<s.length()){
            int start = i;
            ++i;
            while(i<s.length() && s[i]!='+' && s[i]!='-'){++i;}
            if(s[start]=='+'){
                result += muldiv("*"+s.substr(start+1,i-start-1));
            }else{
                result -= muldiv("*"+s.substr(start+1,i-start-1));
            }
        }
        return result;
    }
public:
    int calculate(string s) {
        return addminus("+"+s);
    }
};