/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

please compare with "Find Minimum in Rotated Sorted Array":
https://github.com/JupiterXXX/Leetcode/blob/master/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array/153.%20Find%20Minimum%20in%20Rotated%20Sorted%20Array.h
the difference is marked as below.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(nums[start]<=nums[end])
            return nums[start];
        while((end- start) > 1){
            int mid = (start+end)/2;
            if(nums[mid]<nums[start])
                end = mid;
            else if(nums[mid]>nums[start])
                start = mid;
            else{
            //when nums[mid] == nums[start], we need to do small change and continue the loop.
                ++start;
                --end;
            }
        }
        return nums[end];                
    }
};
