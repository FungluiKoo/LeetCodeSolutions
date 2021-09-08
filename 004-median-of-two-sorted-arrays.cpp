#include <vector>

class Solution {
private:
    // Interval: [Start, End)
    double getMedian(std::vector<int>& arr, size_t start, size_t end) {
        // REQUIRES: 0<=start<=end<=arr.size()
        auto n = end - start;
        if (n==0) {return 0;}
        return (n % 2) ? arr[start+n/2] : (arr[start+n/2]+arr[start+n/2-1])/2.0;
    }

    size_t updateStart(size_t start, size_t end) {
        // REQUIRES: start<=end
        return (start+end)/2;
    }

    size_t updateEnd(size_t start, size_t end) {
        // REQUIRES: start<=end
        return (start+end)/2;
    }

public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        size_t s1 = 0, e1 = nums1.size();
        size_t s2 = 0, e2 = nums2.size();
        size_t total = nums1.size() + nums2.size();
        auto med1 = getMedian(nums1, s1, e2);
        auto med2 = getMedian(nums2, s2, e2);
        if(nums1.empty()){return med2;}
        if(nums2.empty()){return med1;}

        while (s1 + s2 != (total-1)/2) {
            if (med1 < med2) { // med 1 is too small
                s1 = updateStart(s1, e1);
                e2 = updateEnd(s2, e2);
            }else if (med1 > med2){ // med 1 is too large
                e1 = updateEnd(s1, e1);
                s2 = updateStart(s2, e2);
            }else{ // med1 == med2
                
            }
        }
        


    }
};