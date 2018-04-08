/*
https://leetcode.com/problems/find-pivot-index/description/

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
//Because of the range including negative, the sequence of the accumulate_sum doesn't have a order.

*/
#include <vector>
using std::vector;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int nums_sum = 0;
        int leftsum = 0;
        for(int i = 0; i < nums.size(); i++){
            nums_sum += nums[i];            
        }
        for(int i = 0; i <nums.size(); i++){
            if(leftsum == nums_sum - leftsum - nums[i])
                return i;
            leftsum += nums[i];
        }
        return -1;
        
    }
};
