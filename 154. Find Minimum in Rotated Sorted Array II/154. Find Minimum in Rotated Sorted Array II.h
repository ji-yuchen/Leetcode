/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

please compare with "Find Minimum in Rotated Sorted Array":
https://github.com/JupiterXXX/Leetcode/blob/master/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array.h
the difference is marked as below.
*/
#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(start == end)
            return nums[start];
        if(nums[start]<nums[end])
            return nums[start];
        while(start < end){
            int mid=(start + end)/2;
            if(nums[mid] > nums[end]){
                start = mid+1;
            }
            else if(nums[mid] < nums[end]){
                end = mid;
            }
            else if(nums[start]==nums[mid]){
                //num[mid]==num[end]
                start++;
                end--;
            }
            else
                end = mid;
            }
        return nums[end];                
    }
};
