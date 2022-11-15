#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), maxpos = 0;
        for(int i=1; i<n; ++i){
            if(nums[i]>nums[maxpos]){maxpos = i;}
        }
        vector<int> result(n,-1);
        stack<int> monos;
        for(int i=maxpos; i>=0; --i){
            while(!monos.empty() && monos.top()<=nums[i]){
                monos.pop();
            }
            if(!monos.empty()){
                result[i] = monos.top();
            }
            monos.push(nums[i]);
        }
        for(int i=n-1; i>maxpos; --i){
            while(!monos.empty() && monos.top()<=nums[i]){
                monos.pop();
            }
            if(!monos.empty()){
                result[i] = monos.top();
            }
            monos.push(nums[i]);
        }
        return result;
    }
};