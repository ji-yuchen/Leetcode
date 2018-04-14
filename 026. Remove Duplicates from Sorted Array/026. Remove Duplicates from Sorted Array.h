/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Time complexity: O(n); Space complexity: O(1)

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int count = 0;
        if(nums.size()==0)
            return 0;
        while(count < nums.size()){
            if(nums[count]!=nums[res]){
                swap(nums[count],nums[++res]);
            }
            ++count;
        }
        return res+1;
    }
};
