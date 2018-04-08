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
