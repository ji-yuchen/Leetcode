/*
https://leetcode.com/problems/search-insert-position/description/

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

*/
#include <vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        for(int i = 0; i < nums.size(); i++){
            if(target<=nums[i])
                return i;                      
        }
        return nums.size();
    }
};




class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int res = 0;
        if(target > nums[end]){
            return end+1;
        }
        while(start <= end){
            int mid = start + (end-start+1)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        res = start;
        return res;
    }
};
