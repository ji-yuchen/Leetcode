/*
https://leetcode.com/problems/minimum-size-subarray-sum/description/

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

*/

//Time complexity: O(N); Space complexity: O(1)
#include <vector>
#include <limits.h>
using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int right = 0;
        if(nums.size() == 0)
            return 0;
        int sum = nums[left];
        int res = INT_MAX;
        while(right < nums.size()-1){
            if(sum < s){
                sum += nums[++right]; 
            }
            
            while(sum >= s){
                res = min(res, right - left + 1);
                sum -= nums[left++];
            }

        }
        return (res == INT_MAX)? 0:res;
        
    }
};
