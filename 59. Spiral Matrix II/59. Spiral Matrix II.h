/*
https://leetcode.com/problems/spiral-matrix-ii/description/
Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]




*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int k = 1;
        int i = 0;
        while(k <= n*n)
        {
            int j = i;
            while(j < n-i){
                ret[i][j++] = k++;
            }
            j = i+1;
            while(j < n-i){
                ret[j++][n-i-1] = k++;
            }
            j = n-i-1-1;
            while(j>i){// the left_down number will not be drawn in this loop.
                ret[n-i-1][j--] = k++;
            }
            j = n-i-1;
            while(j>i){
                ret[j--][i] = k++;
            }
            ++i;
            
        }
        return ret;
    }
};
