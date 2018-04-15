/*
https://leetcode.com/problems/search-a-2d-matrix/
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


//It's a good problem about binary search. We better review the basic writing of binary search.
//answers here: https://www.zhihu.com/question/36132386, help a lot.
Time complexity: O(logM + logN)
*/
#include <vector>
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int m = matrix.size();
        if(matrix[0].size() == 0)
            return false;
        int n = matrix[0].size();
        int start = 0;
        int end = m - 1;
        int mid;
        while(start < end && matrix[end][0]>target){
            mid = start + (end - start+1)/2;
            if( matrix[mid][0] > target)
                end = mid - 1;
            else if(matrix[mid][0] < target)
                start = mid;
            else 
                return true;
        }
        int row = end;
        start = 0; 
        end = n-1;
        
        while(start < end){
            mid = start + (end -start)/2;
            if(matrix[row][mid] > target)
                end = mid;
            else if(matrix[row][mid] < target)
                start = mid+1;
            else{
                start = mid;
                break;
            }
                
        }
        if(matrix[row][start] == target)
            return true;
        else
            return false;
        
        
    }
};
