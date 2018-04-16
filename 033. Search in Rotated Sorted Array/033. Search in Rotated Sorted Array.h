/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

//It's an enhanced binary search problem=.=
//I have trid some time on boundary condition selection..


#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            if(target<nums[start]&&target>nums[end])
                return -1;
            int mid = start + (end -start)/2;
            if(target == nums[mid])
                return mid;
            // exist rotation, mid is on the right part
            if(nums[mid] < nums[start]){// in condition like "[3,1] 1", we need to use "nums[mid] < nums[start]", not "nums[mid] < nums[end]",because mid may equal start =.=
                if(target > nums[mid]&&target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            //exist rotation, mid is on the left part
            else if(nums[mid] > nums[end]){
                if(target >= nums[start]&&target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
                
            }
            // doesn't exist rotation
            else{
                if(target > nums[mid])
                    start = mid + 1;
                else
                    end = mid - 1;
            }

        }
        return -1;
    }
};
