#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> iq; //increasing queue
        int i = 0;
        for(;i<num.length() && k>0; ++i){
            while(k>0 && !iq.empty() && iq.back()>num[i]){
                iq.pop_back();
                --k;
            }
            iq.push_back(num[i]);
        }
        while(k>0 && !iq.empty()){
            iq.pop_back();
            --k;
        }
        while(!iq.empty() && iq.front()=='0'){iq.pop_front();}
        if(iq.empty()){
            while(i<num.length() && num[i]=='0'){++i;}
        }
        string result;
        for(auto it=iq.begin(); it!=iq.end(); ++it){
            result.push_back(*it);
        }
        result += num.substr(i, num.length()-i);
        return (result=="") ? "0" : result;
    }
};

int main(){
    Solution sol;
    cout << sol.removeKdigits("9",1) << endl;
    return 0;
}