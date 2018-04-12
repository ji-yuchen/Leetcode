/*
https://leetcode.com/problems/pascals-triangle-ii/description/
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Hopefully I find we can let --j to save O(k) space =.=. I haven't thought of it when I do the problem I, sad.
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        for(int i = 1; i <= rowIndex; ++i){
            for(int j = i-1; j > 0; --j){
                res[j] = res[j]+res[j-1];
            }
        }
        return res;
            
        
    }
};
