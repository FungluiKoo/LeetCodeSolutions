#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(vector<int> *nums, int start, int end, int k){
        // find kth smallest element between [start,end)
        if(end-start<1000){
            sort(nums->begin()+start,nums->begin()+end);
            return nums->at(k-1);
        }
        auto medians = new vector<int>;
        for(int prev = start; prev<end;){
            int curr = (end-prev<5) ? end : (prev+5);
            sort(nums->begin()+prev,nums->begin()+curr);
            medians->push_back(nums->at((prev+curr)/2));
            prev = curr;
        }
        auto pivot = helper(medians,0,(end-start+4)/5,(end-start+4)/10+1);
        delete medians;
        int p = partition(nums->begin()+start,nums->begin()+end,\
            [pivot](int x){return x<pivot;}
        )-nums->begin();
        if(k-1<p){
            return helper(nums,start,p,k);
        }else if(k-1==p){
            return pivot;
        }else{
            return helper(nums,p,end,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return helper(&nums, 0, nums.size(), nums.size()+1-k);
    }
};

int main(){
    vector<int> v = {0,1,2,3,4};
    return 0;
}