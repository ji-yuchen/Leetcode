/*
https://leetcode.com/problems/sort-colors/description/
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

//Maybe the "if condition" can be refined in someway=w=.
//Time complexity: O(N); Space complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num_0 = 0;
        int num_2 = 0;
        int i = 0;
        while(i<nums.size()-num_2){
            if(nums[i]==0){
                swap(nums[i],nums[num_0]);
                ++num_0;
                ++i;
            }else if(nums[i]==2){
                swap(nums[i], nums[nums.size() - num_2 - 1]);
                ++num_2;
            }else{
                ++i;
            }
        }
        return;
        
    }
};
