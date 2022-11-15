#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> loc;
        for(int i=0; i<n2; ++i){
            loc[nums2[i]] = i;
        }
        stack<int> monos;
        vector<int> ng(n2,-1);
        for(int i=n2-1; i>=0; --i){
            while(!monos.empty() && monos.top()<=nums2[i]){
                monos.pop();
            }
            if(!monos.empty()){
                ng[i] = monos.top();
            }
            monos.push(nums2[i]);
        }
        vector<int> result(n1);
        for(int i=0; i<n1; ++i){
            result[i] = ng[loc[nums1[i]]];
        }
        return result;
    }
};