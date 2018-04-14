/*
https://leetcode.com/problems/set-matrix-zeroes/description/
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

The problem only allows constant extra space, so we need choose a proper position in the array to store "where to set 0".
I choose the 0 row and 0 col to store while using two marks to store  whether the 0 row and 0 col need to be set 0.
*/
#include <vector>
using std::vector;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false;
        bool col = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j]==0)
                {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
        if(row){
            for(int j = 0; j<matrix[0].size(); j++)
                matrix[0][j] = 0;
        }
        if(col){
            for(int i = 0; i<matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};
