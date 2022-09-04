#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){return 0;}
        int prev = 1, curr = 1;
        for(int i=1; i<s.length(); ++i){
            int temp = (s[i]>'0') ? curr : 0;
            if(s[i-1]=='1' || (s[i-1]=='2'&&s[i]<='6')){temp+=prev;}
            if(temp==0){return 0;}
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};