/*
https://leetcode.com/problems/maximum-average-subarray-i/
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Time complexity: O(N); Space complexity: O(1)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;   
        double sum = 0;
        for(int i = 0 ; i < k ; i++) 
            sum += nums[i];
        res = sum;
        for(int i = k ; i < nums.size(); ++i){
            sum = sum - nums[i-k] + nums[i];
            res = max(res, sum);
        }
        return res/k;
    }
};
