/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.
EXAMPLE:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/
//The core is to find the left and right boundary of the unsorted subarray.
//By finding the first misorder element from left and right, we can continue find the min and max of the unsorted subarray.
//My first solution seems using too many loops=.=
#include<vector>
#include<algorithm>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int max_ = INT_MIN;
        int min_ = INT_MAX;
        bool flag_l = false;
        bool flag_r = false;
        for(int i = 1; i <nums.size(); ++i){
            if(nums[i]<nums[i-1])
                flag_l = true;
            if(flag_l)
                min_ = min(min_, nums[i]);
            if(nums[nums.size() - i - 1] > nums[nums.size()-i])
                flag_r = true;
            if(flag_r)
                max_ = max(max_, nums[nums.size()-i-1]);
        }
        int left = 0;
        int right = nums.size()-1;
        for(;left<nums.size();++left)
            if(nums[left]>min_)
                break;
        for(;right>=0;--right)
            if(nums[right]<max_)
                break;
        return right<left? 0:right - left + 1;
    }
};

//found from submission page=.= 40ms
//It's more clear that we can see what we are doing.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int local_max = INT_MIN;
        int local_min = INT_MAX;
        int left = 0;
        int right = nums.size()-1;
        int start = left;
        int end = right;
        while(left != right && nums[left]<=nums[left+1])++left;
        while(left != right && nums[right]>=nums[right-1])--right;
        if(left==right)return 0;
        for(int i = left; i<=right;++i){
            local_max = max(nums[i],local_max);
            local_min = min(nums[i],local_min);
        }
        while(start <= left && local_min >= nums[start])++start;
        while(end >= right && local_max <= nums[end])--end;
        return end - start + 1;
        
    }
};
