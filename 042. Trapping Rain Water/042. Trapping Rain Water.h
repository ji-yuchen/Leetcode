/*
https://leetcode.com/problems/trapping-rain-water/description/
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
http://www.leetcode.com/static/images/problemset/rainwatertrap.png

QAQ using two points can save space complexity compared with using stack or DP.
Time complexity: O(N); Space complexity: O(1).
*/
#include<vector>
using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int res = 0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>left_max)
                    left_max = height[left];
                else
                    res += left_max - height[left];
                ++left;
            }
            else{
                if(height[right]>right_max)
                    right_max = height[right];
                else
                    res += right_max - height[right];
                --right;
            }
        }
        return res;
        
    }
};
