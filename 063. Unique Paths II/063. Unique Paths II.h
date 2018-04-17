/*
https://leetcode.com/problems/unique-paths-ii/description/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
*/
//Not much difference from "Unique Paths"..

#include <vector>
using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m,vector<int>(n, 0));
        if(obstacleGrid[0][0] == 1)
            return 0;
        else
            path[0][0] = 1;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 0){
                    if(i > 0)
                        path[i][j] += path[i-1][j];
                    if(j > 0)
                        path[i][j] += path[i][j-1];
                }
                
            }
        return path[m-1][n-1];
    }
};
