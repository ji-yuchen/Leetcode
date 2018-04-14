/*
https://leetcode.com/problems/container-with-most-water/description/


Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

//using two points
//Time complexity: O(N); Space complexity: O(1)
*/

#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while(left<right){
            res = max(res, (right - left)*min(height[left], height[right]));
            if(height[left]>height[right])
                --right;
            else
                ++left;
        }
        return res;
        
    }
};
