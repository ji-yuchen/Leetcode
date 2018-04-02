/*
https://leetcode.com/problems/rotate-image/description/

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/
#include<vector>
#include<algorithm>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};
