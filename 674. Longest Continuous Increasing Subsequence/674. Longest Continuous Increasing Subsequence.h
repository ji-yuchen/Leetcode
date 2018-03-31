/*
https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Time complexity : O(N) ; Space complexity : O(1)
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int longest = 0;
        int count = 1;
        if(nums.size() == 0)
            return 0;
        if(nums.size() ==1)
            return 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                count++;
            else
                count = 1;
            if(count > longest)
                longest = count;
        }
        return longest;
    }
};
