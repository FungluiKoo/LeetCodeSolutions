#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution1 { // Dynamic Programming
public:
    string longestPalindrome(string s) {
        int N = s.length();
        string result = s.substr(0,1);
        vector<vector<bool>> dp(N,vector<bool>(N,false));
        for(int i=0; i<N; ++i){dp[i][i] = true;}
        for(int i=1; i<N; ++i){
            if(s[i-1]==s[i]){
                dp[i-1][i] = true;
                if(result.length()<2){result = s.substr(i-1,2);}
            }
        }
        for(int L=2; L<N; ++L){
            for(int i=L; i<N; ++i){
                if(s[i-L]==s[i] && dp[i-L+1][i-1]){
                    dp[i-L][i]=true;
                    if(result.length()<L+1){result = s.substr(i-L,L+1);}
                }
            }
        }
        return result;
    }
};

class Solution2 { // Manacher's Algorithm
private:
    string str = "#";
    int n = 1;
    vector<int> arm;
public:
    string longestPalindrome(string s) { 
        if(s.length()<2){return s;}
        for(auto ch:s){
            str += ch;
            str += '#';
        }
        n = str.length();
        arm.resize(n, 0);
        int center = 0, right = 0, maxarm = 0, max_i = 0;
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
            if(arm[i]>maxarm){
                maxarm = arm[i];
                max_i = i;
            }
        }
        return s.substr((max_i-maxarm)/2, maxarm);
    }
};

int main(){
    Solution2 sol;
    cout << sol.longestPalindrome("babad") << endl;
    return 0;
}