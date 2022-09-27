#include <vector>

using namespace std;

class Solution0 {
private:
    vector<int> arr;
    void helper(int left, int right){
        int n = right-left+1;
        if(n<=2){return;}
        int a0 = arr[left];
        int d = (arr[right]-arr[left])/(right-left);
        int mid = (left+right+1)/2;
        int i=left;
        for(int val=a0+(n%2)*2*d; i<mid; ++i){
            arr[i] = val;
            val += 2*d;
        }
        if(n%2){ // odd
            arr[i++] = a0;
        }
        for(int val=a0+d; i<=right; ++i){
            arr[i] = val;
            val += 2*d;
        }
        helper(left, mid-1);
        helper(mid+(n%2), right);
    }
public:
    vector<int> beautifulArray(int n) {
        for(int i=0; i<n; ++i){arr.push_back(i+1);}
        helper(0,n-1);
        return arr;
    }
};

class Solution {
private:
    vector<int> arr;
    void helper(int left, int right, int a1, int an){
        int n = right-left+1;
        if(n<=2){
            arr[left] = a1;
            if(n==2){arr[right] = an;}
            return;
        }
        int d = (an-a1)/(right-left);
        int mid = (left+right+1)/2;
        if(n%2){ // odd
            arr[mid] = a1;
        }
        helper(left, mid-1, a1+(n%2)*2*d, an+((n%2)-1)*d);
        helper(mid+(n%2), right, a1+d, an-(n%2)*d);
    }
public:
    vector<int> beautifulArray(int n) {
        arr.resize(n);
        helper(0,n-1, 1, n);
        return arr;
    }
};