/*
https://leetcode.com/problems/triangle/description/
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
 

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).


using bottom-up DP, saves some space.
Time complexity: O(N^2); Space complexity: O(N)

*/

#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        if(height == 0)
            return 0;
        vector<int> minmum(triangle.back());
        for(int i = height - 2; i>=0; --i){
            for(int j = 0; j <= i; ++j){
                minmum[j] = min(minmum[j], minmum[j+1]) + triangle[i][j];
            }
        }
        return minmum[0];        
    }
};
