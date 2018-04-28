/*
https://leetcode.com/problems/majority-element-ii/description/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
//Pay attention to "⌊ n/3 ⌋",which means we can have two elements at most as result.So we maintain two candidates and two counts to store the most and second most elements.
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int can1 = 0;
        int can2 = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == can1)
                ++count1;
            else if(nums[i] == can2)
                ++count2;
            else if(count1==0){
                can1 = nums[i];
                ++count1;
            }
            else if(count2==0){
                can2 = nums[i];
                ++count2;
            }else{
                --count1;
                --count2;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]==can1)
                ++count1;
            else if(nums[i]==can2)
                ++count2;
        }
        vector<int> res;
        if(count1>(nums.size()/3))res.push_back(can1);
        if(count2>(nums.size()/3))res.push_back(can2);
        return res;
        
    }
};
