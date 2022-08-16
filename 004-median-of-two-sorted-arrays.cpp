#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getk(vector<int>& nums1, vector<int>& nums2, int k){
        int n1 = nums1.size(), n2=nums2.size();
        if(n1==0){return nums2[k-1];}
        if(n2==0){return nums1[k-1];}
        // if(nums1[n1-1]<=nums2[0]){
        //     return (k<=n1) ? nums1[k-1] : nums2[k-n1-1]; 
        // }        
        if(upper_bound(nums1.cbegin(),nums1.cend(),nums2[0])-nums1.cbegin()>=k){return nums1[k-1];}
        if(lower_bound(nums2.cbegin(),nums2.cend(),nums1[n1-1])-nums2.cbegin()<k-n1){return nums2[k-n1-1];}
        // if(nums2[n2-1]<=nums1[0]){
        //     return (k<=n2) ? nums2[k-1] : nums1[k-n2-1];
        // }
        if(upper_bound(nums2.cbegin(),nums2.cend(),nums1[0])-nums2.cbegin()>=k){return nums2[k-1];}
        if(lower_bound(nums1.cbegin(),nums1.cend(),nums2[n2-1])-nums1.cbegin()<k-n2){return nums1[k-n2-1];}
        
        // now the answer must be in the overlapped part
        int left=max(1,k-n2), right=min(k-1,n1);
        int x = (left+right)/2;
        while(left<right){
            if(nums2[k-x-1]>nums1[x]){ // x too small
                left = (left==right-1) ? (left+1) : x;
            }else if(k-x<n2 && nums1[x-1]>nums2[k-x]){ // x too large
                right = x;
            }else{
                break;
            }
            x = (left+right)/2;
        }
        return max(nums1[x-1],nums2[k-x-1]);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        if(n==0){ // both empty
            return 0.0;
        }else if(n % 2){ // odd
            return double(getk(nums1,nums2,(n+1)/2));
        }else{ // even
            return (getk(nums1,nums2,n/2)+getk(nums1,nums2,n/2+1))/2.0;
        }
    }
};

int main(){
    Solution sol;
    vector<int> a1 = {1,2};
    vector<int> a2 = {1,2};
    cout << sol.getk(a1,a2,2) << endl << sol.getk(a1,a2,3) << endl;
    return 0;
}