/*
https://leetcode.com/problems/3sum-closest/description/


Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

*/

//Time complexity: O(N^2); Space complexity: O(1)

#include<vector>
#include<algorithm>
using std::vector;
using std::abs;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        int res = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int first = i+1;
            int end = nums.size() - 1;
            while(first < end){
                int sum = nums[i] + nums[first] + nums[end];
                if(abs(res - target)>abs(sum - target))
                    res = sum;                
                if(sum == target)
                    return sum;
                else if(sum > target){
                    --end;                
                }else if(sum < target){
                    ++first;    
                }                
                
            }
        }
        return res;
    }
};
