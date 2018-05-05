/*
https://leetcode.com/problems/non-decreasing-array/description/

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.

Note: The n belongs to [1, 10,000].
*/
//consider tow condition:
//[5,7,1,8] so 1->7
//[5,7,6,8] so 7->6
//Then continue to process next element
//Time complexity: O(N); Space complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<1)
            return true;
        int cnt = 0;
        for(int i = 1; i<nums.size(); ++i){
            if(nums[i]<nums[i-1]){
                if(nums[i-2]<=nums[i]){
                    nums[i-1] = nums[i];
                    ++cnt;
                }else{
                    nums[i] = nums[i-1];
                    ++cnt;
                }            
            }            
        }
        if(cnt>1)
                return false;
        else
            return true;
        
    }
};
