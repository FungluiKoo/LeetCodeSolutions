#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(b.length()>a.length()){swap(a,b);}
        int carryover = 0, x = a.length()-1, y = b.length()-1;
        for(; y>=0; --x,--y){
            carryover += (a[x]-'0') + (b[y]-'0');
            a[x] = '0'+(carryover & 0b1);
            carryover >>= 1;
        }
        for(; x>=0; --x){
            carryover += (a[x]-'0');
            a[x] = '0'+(carryover & 0b1);
            carryover >>= 1;
        }
        if(carryover){
            a = '1' + a;
        }
        return a;
    }
};

int main(){
    Solution sol;
    string a, b;
    while(true){
        cin >> a;
        cin >> b;
        cout << sol.addBinary(a,b) << endl;
    }
    return 0;
}