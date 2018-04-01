/*
https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

*/

//Time complexity: O(N) ; Space complexity: O(1)
//In fact, traverse the array twice will save some time comparing with this method i wrote. =.=
#include<vector>
using std::vector;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_1 = 0;
        int max_2 = 1;
        if(nums.size() == 1)
            return 0;
        if(nums[max_1]<nums[max_2])
        {
            max_1 = 1;
            max_2 = 0;
        }
        for(int i = 2; i< nums.size(); i++)
        {
            if(nums[i]>nums[max_1])
            {
                max_2 = max_1;
                max_1 = i;
            }else if(nums[i]>nums[max_2])
            {
                max_2 = i;
            }
        }
        if (nums[max_1]<nums[max_2]*2)
            return -1;
        else 
            return max_1;
            
    }
};
