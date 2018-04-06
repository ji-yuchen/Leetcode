/*
https://leetcode.com/problems/pascals-triangle/description/
Given numRows, generate the first numRows of Pascal's triangle.

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> initial_row;
        if(numRows ==0)
            return ret;
        for(int i = 0 ; i < numRows; i++){
            generate_Pascal_one(initial_row);
            ret.push_back(initial_row);
        }
        return ret;
            
        
    }
    void generate_Pascal_one(vector<int> & A){
        int index = A.size();
        vector<int> B(A);
        for(int i = 1; i < index; i++){            
            A[i] = B[i-1] + B[i];
        }            
        A.push_back(1);
        return;
    }
};
