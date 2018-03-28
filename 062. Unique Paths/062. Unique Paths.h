/*
https://leetcode.com/problems/unique-paths/description/


A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

//there are some works on how to save space. The original, unoptimized way is use path[][] to store num of paths at each grid, whose space complexity is O(mn).

time complexity:O(mn), space complexity: O(m).
*/



class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n)
            return uniquePaths(n,m);
        vector<int> path(m, 1);
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
            {
                path[j] += path[j-1];
            }
        return path[m-1];
    }
};
