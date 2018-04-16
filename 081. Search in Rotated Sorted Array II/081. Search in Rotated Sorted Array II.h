/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/
//duplicates force us to do a little change, just as follow.
//same thoughts in "find-minimum-in-rotated-sorted-array".

#include<vector>
using std::vector;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            if(target<nums[start]&&target>nums[end])
                return false;
            int mid = start + (end -start)/2;
            if(target == nums[mid])
                return true;
            
            //The only difference with the no-duplicate problem.
            if(nums[start] == nums[mid]&&nums[mid] == nums[end]){
                ++start;
                --end;
            }
            
            // exist rotation, mid is on the right part    
            else if(nums[mid] < nums[start]){// in condition like "[3,1] 1", we need to use "nums[mid] < nums[start]", not "nums[mid] < nums[end]",because mid may equal start =.=
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
        return false;
    }
};
