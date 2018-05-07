/*
https://leetcode.com/problems/first-missing-positive/description/
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time and uses constant extra space.
*/
//Put nums[i] in right place: nums[nums[i] - 1]
//Remember repeat until the new nums[i] satisfy nums[i] == nums[nums[i] - 1] or it is out of [1,n]

#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
        
    }
};
