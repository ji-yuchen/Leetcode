/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

//An extra loop based on "3Sum" solution.

#include<vector>
#include<algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)return{};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int j = 0; j<nums.size()-3;++j){
            
            for(int i = j+1; i<nums.size()-2;++i){
             
                int start = i+1;
                int end = nums.size()-1;
                while(start<end){
                    if(nums[j]+nums[i]+nums[start]+nums[end]==target){
                        res.push_back({nums[j],nums[i],nums[start],nums[end]});
                        ++start;
                        --end;
                        while((start<end)&&(nums[start]==nums[start-1]))++start;
                        while((start<end)&&(nums[end]==nums[end+1]))--end;                    
                    }
                    else if(nums[j]+nums[i]+nums[start]+nums[end]<target){
                        ++start;
                    }else{
                        --end;
                    }
                }
                
                while((i+1<nums.size())&&(nums[i+1]==nums[i])) ++i;//cool!
            }
        while(j+1<nums.size()&&nums[j+1]==nums[j]) ++j;
        }
        return res;
        
    }
};
