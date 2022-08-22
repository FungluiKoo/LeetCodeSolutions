#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string str = "#";
    int n = 1;
    vector<int> arm;

public:
    int countSubstrings(string s) {
        if(s.length()<2){return 1;}
        for(auto ch:s){
            str += ch;
            str += '#';
        }
        n = str.length();
        arm.resize(n, 0);
        int center = 0, right = 0, result = 0;
        for(int i=1; i<n-1; ++i){
            if(i<right){
                arm[i] = min(arm[2*center-i], right-i);
            }
            while(i-arm[i]-1>=0 && i+arm[i]+1<n\
                 && str[i-arm[i]-1]==str[i+arm[i]+1]){
                ++arm[i];
            }
            if(i+arm[i]>right){
                center = i;
                right = i+arm[i];
            }
            result += (arm[i]+1)/2;
        }
        return result;
    }
};