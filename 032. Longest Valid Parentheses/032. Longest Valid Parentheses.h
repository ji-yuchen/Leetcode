/*
https://leetcode.com/problems/longest-valid-parentheses/description/
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

*/
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::max
//dynamic programming
//Time complexity: O(N); Space complexity: O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = (i >=2 ? dp[i-2]:0) + 2;
                }else if(i-dp[i-1] >0 && s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + ((i-dp[i-1]) >=2 ? dp[i-dp[i-1]-2]:0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
        
    }
};

//Stack
//Time complexity: O(N); Space complexity: O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> tmp;
        tmp.push(-1);
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                tmp.push(i);
            }else{
                tmp.pop();
                if(tmp.empty()){
                    tmp.push(i);
                }else{
                    res = max(res, i - tmp.top());
                }
            }
        }
        return res;
        
    }
};

//Time complexity: O(N); Space complexity: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left, right = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                ++left;
            }else{
                ++right;
            }
            if(left == right){
                res = max(res, 2*right);
            }else if (right >= left){
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i = s.size()-1; i >=0; --i){
            if(s[i] == '('){
                ++left;
            }else{
                ++right;
            }
            if(left == right){
                res = max(res, 2*left);
            }else if (left >= right){
                left = 0;
                right = 0;
            }
        }
        return res;
        
    }
};
