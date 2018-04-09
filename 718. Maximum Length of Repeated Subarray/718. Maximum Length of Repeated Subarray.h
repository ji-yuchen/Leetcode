/*
https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

*/
//DP solution.
//Time complexity: O(MN); Space complexity: O(MN) ->can be reduced to O(M)
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int size_A = A.size();
        int size_B = B.size();
        vector<vector<int>> ReSub (size_A+1, vector<int>(size_B+1, 0));
        int ret = 0;
        for(int i = size_A - 1; i>=0; --i){
            for(int j = size_B - 1; j>=0; --j){
                
                if(A[i]==B[j]){//Only in this condition, the information need update.
                    ReSub[i][j] = ReSub[i+1][j+1];
                    ReSub[i][j] += 1;
                    if(ret<ReSub[i][j])
                        ret = ReSub[i][j];
                }

            }
        }
        return ret;
    }
};
