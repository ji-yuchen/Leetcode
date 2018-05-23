/*
https://leetcode.com/problems/longest-palindromic-substring/description/
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/
#include <string>
#include <algorithm>
using std::string;
using std::max;
//EXPAND AROUND CENTER
//Time complexity: O(N^2); Space complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        for(int i = 0; i<s.size();++i){
            int len1 = ExpandAroundCenter(s, i, i);
            int len2 = ExpandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end-start+1);
    }
    
private:
    int ExpandAroundCenter(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        return right-left-1;
    }
};

//DYNAMIC PROGRAMMING
//Time compelxity: O(N^2); Space complexity: O(N^2)
//dp[i][j] == True means substring(i,j) is palindromic
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n-1; i>=0; --i){
            for(int j = i; j<n; ++j){
                dp[i][j] = (s[i] == s[j]) && (j-i<3 || dp[i+1][j-1]);
                if(dp[i][j]&&(j-i+1 > res.size())){
                    res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
};
