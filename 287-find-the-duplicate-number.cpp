#include <cmath>
#include <vector>

using namespace std;


class Solution {
    // Mark negative
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            if(nums[abs(nums[i])]<0){
                return abs(nums[i]);
            }
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        return 0;
    }
};

class Solution2 { 
    // Fast and slow pointers
    // Find linked list cycle
public:
    int findDuplicate(vector<int>& nums) {
        int turtle = nums[0], rabbit = nums[0];
        do{
            turtle = nums[turtle];
            rabbit = nums[nums[rabbit]];
        }while(turtle!=rabbit);
        turtle = nums[0];
        while(turtle!=rabbit){
            turtle = nums[turtle];
            rabbit = nums[rabbit];
        }
        return rabbit;
    }
};