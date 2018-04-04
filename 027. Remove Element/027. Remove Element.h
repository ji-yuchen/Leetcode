/*
https://leetcode.com/problems/remove-element/description/

Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


//Using end = size() helps solve the "[1] 1" condition.

Time complexity : O(N) ; Space complexity : O(1)
*/

#include<vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size();
        if(end<0)
            return 0;
        while(start != end){
            if(nums[start] == val){
                nums[start] = nums[end-1];
                end--;
            }
            else{
                start++;
            }
           
        }
        return start;
        
    }
};
