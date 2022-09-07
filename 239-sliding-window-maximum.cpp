#include <deque>
#include <vector>

using namespace std;

class Solution {
private:
    deque<int> dq; // decreasing queue
    void push(int x){
        while(!dq.empty() && dq.back()<x){dq.pop_back();}
        dq.push_back(x);
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){return nums;}
        for(int i=0; i<k-1; ++i){push(nums[i]);}
        vector<int> result(nums.size()-k+1);
        for(int i=k-1; i<nums.size(); ++i){
            push(nums[i]);
            result[i-k+1] = dq.front();
            if(dq.front()==nums[i-k+1]){dq.pop_front();}
        }
        return result;
    }
};