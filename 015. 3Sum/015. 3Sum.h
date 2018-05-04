/*
https://leetcode.com/problems/3sum/description/
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
//The difference between "2Sum" and "3Sum" is not only "2or3", but also returning "index or value".
//3Sum returns values, which is convinient for us to use sort.
//The basic idea is use an extra loop. For each "i" in nums, calculate if existing two suitable values on the right of it.
//Use sort and two points.
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)return{};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2;++i){
            if(i>0&&nums[i]==nums[i-1])continue; 
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                if(nums[i]+nums[start]+nums[end]==0){
                    res.push_back({nums[i],nums[start],nums[end]});
                    ++start;
                    --end;
                    while((start<end)&&(nums[start]==nums[start-1]))++start;
                    while((start<end)&&(nums[end]==nums[end+1]))--end;                    
                }
                else if(nums[i]+nums[start]+nums[end]<0){
                    ++start;
                    //while((start<end)&&(nums[start]==nums[start-1]))++start;
                }else{
                    --end;
                    //while((start<end)&&(nums[end]==nums[end+1]))--end;
                }
            }
            //++i;
            //while((i<nums.size())&&(nums[i]==nums[i-1]))++i;//cool!
        }
        return res;
        
    }
};
