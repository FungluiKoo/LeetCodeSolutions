#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getk(vector<int>& nums1, vector<int>& nums2, int k){
        int n1 = nums1.size(), n2=nums2.size();
        if(n1==0 || (n2>=k && nums1[0]>=nums2[k-1])){return nums2[k-1];}
        if(n2==0 || (n1>=k && nums2[0]>=nums1[k-1])){return nums1[k-1];}
        
        if(n1+n2==k || (k>n1 && nums1[n1-1]<=nums2[k-n1])){return max(nums1[n1-1],nums2[k-n1-1]);}
        if(n1+n2==k || (k>n2 && nums2[n2-1]<=nums1[k-n2])){return max(nums2[n2-1],nums1[k-n2-1]);}
        
        // now the answer must be in the overlapped part
        int left=max(1,k-n2+1), right=min(k,n1);
        int x = (left+right)/2;
        while(left<right-1){
            if(nums1[x]<nums2[k-x-1]){ // x too small
                left = x;
            }else if(nums1[x-1]>nums2[k-x]){ // x too large
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