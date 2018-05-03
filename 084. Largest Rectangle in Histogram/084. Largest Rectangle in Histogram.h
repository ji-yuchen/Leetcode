/*
https://leetcode.com/problems/largest-rectangle-in-histogram/description/
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Example:
Input: [2,1,5,6,2,3]
Output: 10
*/
//Use a stack. Keep pushing in until heights[i]>heights[i+1]. Let the back out and calculate the largest area.
#include<vector>
using std::vector;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        vector<int> tmp;
        for(int i = 0; i < heights.size(); ++i){
            while(tmp.size()>0 && heights[tmp.back()]>=heights[i]){                
                int h = heights[tmp.back()];
                tmp.pop_back();
                int idx = tmp.size() > 0? tmp.back():-1;                
                res = max(res, h*(i-idx-1));
            }
            tmp.push_back(i);
        }
        return res;
        
    }
};
