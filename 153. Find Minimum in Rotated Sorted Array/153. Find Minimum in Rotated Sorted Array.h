/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

It's a classical problem which i feel funny doing with.

Time complexity: O(logN) ; Space complexity: O(1)
*/

#include <vector>
using std::vector

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(nums[start]<=nums[end])
            return nums[start];
        while((end- start) > 1){
            int mid = (start+end)/2;
            if(nums[mid]<nums[start])
                end = mid;
            else
                start = mid;
        }
        return nums[end];
    }
};
