/*
https://leetcode.com/problems/delete-operation-for-two-strings/description/
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/
//Use dynamic programming. Use a 2-D array to store the length of common subarray of word1 and word2.
for example "sea", "eat":
dp:
  0 s e a
0 0 0 0 0
e 0 0 1 1
a 0 0 1 2
t 0 0 1 2
output: 3+3-2*2=2

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(i==0||j==0)
                    continue;
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m + n - 2*dp[m][n];
    }
};
