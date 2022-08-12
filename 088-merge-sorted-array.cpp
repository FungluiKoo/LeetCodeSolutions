#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        queue<int> q1;
        for(int i=0; i<m; i++){q1.push(nums1[i]);}
        int k=0;
        for(int i=0; i<n; i++){
            while(!q1.empty() && q1.front()<=nums2[i]){
                nums1[k++] = q1.front();
                q1.pop();
            }
            nums1[k++] = nums2[i];
        }
        while(!q1.empty()){
            nums1[k++] = q1.front();
            q1.pop();
        }
    }
};