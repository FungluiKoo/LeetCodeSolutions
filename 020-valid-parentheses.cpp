#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch: s){
            if(ch=='['||ch=='{'){
                st.push(char(ch+2));
            }else if(ch=='('){
                st.push(')');
            }else if(st.empty()||st.top()!=ch){
                return false;
            }else{
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){
    Solution sol;
    string str;
    while(str!="q"){
        cin >> str;
        cout << sol.isValid(str) << "\n";
    }
    return 0;
}