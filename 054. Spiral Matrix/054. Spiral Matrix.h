/*
https://leetcode.com/problems/spiral-matrix/description/
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

The index need some attention... I spent some time with it.
*/
#include <vector>
using std::vector

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ret;
        int m = matrix.size();
        if(m==0)
            return ret;
        int n = matrix[0].size();
        if(n==0)
            return ret;
        int i = 0;
        int j = 0;
        int num_m = m;
        int num_n = n;
        while(num_m>1&&num_n>1){
            j = i;
            while(j < n-i){
                ret.push_back(matrix[i][j++]);
            }
            --num_m;
            j = i+1;
            while(j < m-i){
                ret.push_back(matrix[j++][n-i-1]);        
            }
            --num_n;
            j = n-i-2;
            while(j>=i){
                ret.push_back(matrix[m-i-1][j--]);
            }
            --num_m;
            j = m-i-2;
            while(j>i){
                ret.push_back(matrix[j--][i]);
            }
            --num_n;
            ++i;
                
        }
        if(num_m==1)
        {
            for(j = i; j<=n-i-1; j++)
                ret.push_back(matrix[i][j]);
        }
        else if(num_n==1)
        {
            for(j = i; j<=m-i-1; j++)
                ret.push_back(matrix[j][i]);
        }
        return ret;
            
    }
};
